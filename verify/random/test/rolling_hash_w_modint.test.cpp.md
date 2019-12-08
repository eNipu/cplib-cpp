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


# :warning: random/test/rolling_hash_w_modint.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B)


## Dependencies
* :warning: [modulus/modint_fixed.hpp](../../../library/modulus/modint_fixed.hpp.html)
* :warning: [random/rolling_hash_1d_general.hpp](../../../library/random/rolling_hash_1d_general.hpp.html)
* :warning: [random/xorshift.hpp](../../../library/random/xorshift.hpp.html)


## Code
```cpp
#include <iostream>
#include <string>
#include "random/rolling_hash_1d_general.hpp"
#include "modulus/modint_fixed.hpp"
#include "random/xorshift.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
using namespace std;

using mint = ModInt<998244353>;
int main()
{
    mint b1(rand_int() % 1000000 + 1), b2(rand_int() % 1000000 + 1);

    string T, P;
    cin >> T >> P;
    rolling_hash<mint> rh_T1(T, b1),rh_P1(P, b1);
    rolling_hash<mint> rh_T2(T, b2),rh_P2(P, b2);

    for (int l = 0; l < (int)(T.length() - P.length() + 1); l++)
    {
        if (rh_T1.get_hash(l, l + P.length()) == rh_P1.get_hash(0, P.length())
            and rh_T2.get_hash(l, l + P.length()) == rh_P2.get_hash(0, P.length()))
        {
            cout << l << endl;
        }
    }
}

```

[Back to top page](../../../index.html)

