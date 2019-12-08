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


# :heavy_check_mark: linear_algebra_matrix/test/linalg_bitset.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624)


## Dependencies
* :heavy_check_mark: [linear_algebra_matrix/linalg_bitset.hpp](../../../library/linear_algebra_matrix/linalg_bitset.hpp.html)


## Code
```cpp
#include <iostream>
#include <numeric>
#include "linear_algebra_matrix/linalg_bitset.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624"

int main()
{
    int N, T;
    cin >> N;
    vector<bitset<Wmax>> A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            A[i][j] = t;
        }
    }
    bitset<Wmax> v(N);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v[i] = t;
    }
    cin >> T;
    A = matpower(A, T);
    for (int i = 0; i < N; i++) A[i][N] = v[i];
    A = gauss_jordan(N + 1, A);

    for (int i = 0; i < N; i++)
    {
        if (A[i].count() == 1 and A[i][N])
        {
            cout << "none" << endl;
            return 0;
        }
    }
    if (!A[N - 1][N - 1])
    {
        cout << "ambiguous" << endl;
        return 0;
    }
    bitset<Wmax> ret;
    for (int i = N - 1; i >= 0; i--)
    {
        int a = 0;
        for (int j = i + 1; j < N; j++) a ^= ret[j] * A[i][j];
        ret[i] = (a != A[i][N]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", ret[i] ? 1 : 0);
    }
    puts("");
}

```

[Back to top page](../../../index.html)

