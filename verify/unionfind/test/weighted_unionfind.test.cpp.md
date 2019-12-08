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


# :warning: unionfind/test/weighted_unionfind.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=jp](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=jp)


## Dependencies
* :warning: [unionfind/weighted_unionfind.hpp](../../../library/unionfind/weighted_unionfind.hpp.html)


## Code
```cpp
#include <iostream>
#include "unionfind/weighted_unionfind.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=jp"
using namespace std;

int main()
{
    int N, Q, x, y, z;
    cin >> N >> Q;
    WeightedUnionFind<int> uf(N);
    for (int i = 0; i < Q; i++)
    {
        int c;
        cin >> c;
        if (c)
        {
            cin >> x >> y;
            if (uf.same(x, y))
            {
                cout << uf.diff(x, y) << endl;
            }
            else
            {
                cout << "?" << endl;
            }
        }
        else
        {
            cin >> x >> y >> z;
            uf.unite(x, y, z);
        }
    }
}

```

[Back to top page](../../../index.html)

