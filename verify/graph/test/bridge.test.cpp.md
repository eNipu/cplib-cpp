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


# :warning: graph/test/bridge.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B)


## Dependencies
* :warning: [graph/lowlink.hpp](../../../library/graph/lowlink.hpp.html)


## Code
```cpp
#include <iostream>
#include <utility>
#include "graph/lowlink.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

int main()
{
    int V, E;
    cin >> V >> E;
    UndirectedGraph graph(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        if (s > t) swap(s, t);
        graph.add_edge(s, t);
    }
    graph.dfs_lowlink(0);
    graph.detectBridge();

    vector<pair<int, int>> bridges;
    for (int i = 0; i < E; i++) {
        if (graph.isBridge[i]) {
            bridges.emplace_back(graph.edges[i]);
        }
    }
    sort(bridges.begin(), bridges.end());
    for (auto pa : bridges) {
        printf("%d %d\n", pa.first, pa.second);
    }
}

```

[Back to top page](../../../index.html)

