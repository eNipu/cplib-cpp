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


# :warning: graph-tree/test/lca.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/lca](https://judge.yosupo.jp/problem/lca)


## Dependencies
* :warning: [graph-tree/lowest_common_ancestor.hpp](../../../library/graph-tree/lowest_common_ancestor.hpp.html)


## Code
```cpp
#include <iostream>
#include "graph-tree/lowest_common_ancestor.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

int main()
{
    int N, Q, p, u, v;
    cin >> N >> Q;
    UndirectedWeightedTree graph(N);
    for (int i = 1; i <= N - 1; i++) {
        cin >> p;
        graph.add_edge(i, p, 1);
    }
    graph.fix_root(0);
    graph.doubling_precalc();

    for (int i = 0; i < Q; i++) {
        cin >> u >> v;
        cout << graph.lowest_common_ancestor(u, v) << endl;
    }
}

```

[Back to top page](../../../index.html)

