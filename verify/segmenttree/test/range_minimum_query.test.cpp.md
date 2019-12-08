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


# :warning: segmenttree/test/range_minimum_query.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A)


## Dependencies
* :warning: [segmenttree/range_minimum_query.hpp](../../../library/segmenttree/range_minimum_query.hpp.html)


## Code
```cpp
#include <iostream>
#include "segmenttree/range_minimum_query.hpp"
using namespace std;
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"


int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, (1LL << 31) - 1);
    RangeMinimumQuery rmq(A, A[0]);
    for (int q = 0; q < Q; q++)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0)
        {
            rmq.update(x, y);
        }
        else
        {
            cout << rmq.get(x, y + 1) << endl;
        }
    }
}

```

[Back to top page](../../../index.html)

