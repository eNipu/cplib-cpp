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


# :warning: graph/test/dijkstra.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A)


## Dependencies
* :warning: [graph/dijkstra.hpp](../../../library/graph/dijkstra.hpp.html)


## Code
```cpp
#include <iostream>
#include <vector>
#include "graph/dijkstra.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

wedges e;

int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    e.resize(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        e[s].emplace_back(t, d);
    }
    auto ret = dijkstra(V, r, e);

    for (int i = 0; i < V; i++) {
        if (ret.first[i] == INF) puts("INF");
        else printf("%lld\n", ret.first[i]);
    }
}
```

[Back to top page](../../../index.html)

