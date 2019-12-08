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


# :heavy_check_mark: string/test/z_algorithm.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B)


## Dependencies
* :heavy_check_mark: [string/z_algorithm.hpp](../../../library/string/z_algorithm.hpp.html)


## Code
```cpp
#include <iostream>
#include <string>
#include <vector>
#include "string/z_algorithm.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
using namespace std;

int main()
{
    string T, P;
    cin >> T >> P;
    vector<int> z = z_algorithm(P + "_" + T);
    int n = P.length();
    for (int i = n + 1; i < (int)z.size(); i++)
    {
        if (z[i] == n) printf("%d\n", i - n - 1);
    }
}
```

[Back to top page](../../../index.html)

