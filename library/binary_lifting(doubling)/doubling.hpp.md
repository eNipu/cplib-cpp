<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: binary_lifting(doubling)/doubling.hpp
* category: binary_lifting(doubling)


[Back to top page](../../index.html)



## Code
```cpp
/*
Binary Lifting / `Doubling`
<https://atcoder.jp/contests/arc060/submissions/7039451>
*/
#pragma once
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#include <cstdlib>
#include <vector>
using namespace std;

struct Doubling
{
    int N, INVALID, lgD;
    vector<vector<int>> mat;
    Doubling() : N(0), lgD(0) {}
    Doubling(const vector<int> &vec_nxt, int INVALID=-1, int lgd = 0) : N(vec_nxt.size()), INVALID(INVALID), lgD(lgd)
    {
        while ((1 << lgD) < N) lgD++;
        mat.assign(lgD, vector<int>(N, INVALID));
        mat[0] = vec_nxt;
        REP(i, N) if (mat[0][i] < 0 or mat[0][i] >= N) mat[0][i] = INVALID;
        REP(d, lgD - 1) REP(i, N) if (mat[d][i] != INVALID) mat[d + 1][i] = mat[d][mat[d][i]];
    }
    int kth_next(int now, int k)
    {
        if (k >= (1 << lgD)) exit(8);
        for (int d = 0; k and now != INVALID; d++, k >>= 1) if (k & 1) now = mat[d][now];
        return now;
    }

    int distance(int l, int r) // Distance from l to [r, \infty) (Monotonic increasing)
    {
        if (l >= r) return 0;
        int ret = 0;
        IREP(d, lgD)
        {
            if (mat[d][l] < r and mat[d][l] != INVALID) ret += 1 << d, l = mat[d][l];
        }
        if (mat[0][l] == INVALID or mat[0][l] >= r) return ret + 1;
        else return -1; // Unable to reach
    }
};

```

[Back to top page](../../index.html)

