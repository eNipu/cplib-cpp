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


# :heavy_check_mark: linear_algebra_matrix/test/linalg_longlong_matmul.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D&lang=jp](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D&lang=jp)


## Dependencies
* :heavy_check_mark: [linear_algebra_matrix/linalg_longlong.hpp](../../../library/linear_algebra_matrix/linalg_longlong.hpp.html)


## Code
```cpp
#include <iostream>
#include "linear_algebra_matrix/linalg_longlong.hpp"
using namespace std;
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D&lang=jp"
using lint = long long;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, M, L;
    cin >> N >> M >> L;
    vector<vector<lint>> A(N, vector<lint>(M)), B(M, vector<lint>(L));
    cin >> A >> B;
    auto C = matmul(A, B, 1e13);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L - 1; j++) {
            printf("%lld ", C[i][j]);
        }
        printf("%lld\n", C[i].back());
    }
}

```

[Back to top page](../../../index.html)

