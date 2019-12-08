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


# :warning: prime/test/gen_primes.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C)


## Dependencies
* :warning: [prime/prime.hpp](../../../library/prime/prime.hpp.html)


## Code
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include "prime/prime.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
using namespace std;

int main()
{
    vector<int> primes = gen_primes(10000);
    int N;
    cin >> N;
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        bool flg = true;
        for (auto p : primes) if (x % p == 0 and x != p)
        {
            flg = false;
            break;
        }
        ret += flg;
    }
    cout << ret << endl;
}

```

[Back to top page](../../../index.html)

