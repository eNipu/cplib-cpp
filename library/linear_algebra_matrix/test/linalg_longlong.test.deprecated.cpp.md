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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: linear_algebra_matrix/test/linalg_longlong.test.deprecated.cpp
* category: linear_algebra_matrix/test


[Back to top page](../../../index.html)



## Dependencies
* :heavy_check_mark: [linear_algebra_matrix/linalg_longlong.hpp](../linalg_longlong.hpp.html)


## Code
```cpp
#include <iostream>
#include <numeric>
#include "linear_algebra_matrix/linalg_longlong.hpp"
#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, T;
    cin >> N;
    vector<vector<lint>> A(N, vector<lint>(N));
    cin >> A;
    vector<lint> v(N);
    cin >> v >> T;
    A = matpower(A, T, 2);
    vector<vector<lint>> B = A;
    for (int i = 0; i < N; i++) B[i].push_back(v[i]);
    B = gauss_jordan(B, 2);
    for (int i = 0; i < N; i++)
    {
        if (accumulate(B[i].begin(), B[i].begin() + N, 0) == 0 and B[i][N])
        {
            cout << "none" << endl;
            return 0;
        }
    }
    int rnk = rank_gauss_jordan(B);
    if (rnk < N)
    {
        cout << "ambiguous" << endl;
        return 0;
    }
    vector<lint> ret(N);
    for (int i = N - 1; i >= 0; i--)
    {
        int a = 0;
        for (int j = i + 1; j < N; j++) a += ret[j] * B[i][j];
        ret[i] = (a % 2 != B[i][N]);
    }
    for (auto v : ret) printf("%lld ", v);
    puts("");
}

```

[Back to top page](../../../index.html)

