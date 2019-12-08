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


# :warning: formal_power_series/test/fps_exp.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/exp_of_formal_power_series](https://judge.yosupo.jp/problem/exp_of_formal_power_series)


## Dependencies
* :warning: [formal_power_series/formal_power_series.hpp](../../../library/formal_power_series/formal_power_series.hpp.html)
* :warning: [modulus/modint_fixed.hpp](../../../library/modulus/modint_fixed.hpp.html)


## Code
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include <iostream>
#include "modulus/modint_fixed.hpp"
#include "formal_power_series/formal_power_series.hpp"
using namespace std;

int main()
{
    int N;
    cin >> N;
    FormalPowerSeries<ModInt<998244353>> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    A.shrink();
    auto ret = A.exp(N);
    for (int i = 0; i < N; i++) printf("%d ", ret.coeff(i).val);
}

```

[Back to top page](../../../index.html)

