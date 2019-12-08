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


# :warning: modulus/test/sqrt_modint_runtime.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/sqrt_mod](https://judge.yosupo.jp/problem/sqrt_mod)


## Dependencies
* :warning: [modulus/modint_runtime.hpp](../../../library/modulus/modint_runtime.hpp.html)


## Code
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include <iostream>
#include "modulus/modint_runtime.hpp"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int Y, P;
        cin >> Y >> P;
        ModIntRuntime::mod = P;
        ModIntRuntime m = Y;
        if (Y) {
            m = m.sqrt();
            cout << (m ? m.val : -1) << endl;
        }
        else cout << 0 << endl;
    }
}

```

[Back to top page](../../../index.html)

