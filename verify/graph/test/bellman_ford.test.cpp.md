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


# :warning: graph/test/bellman_ford.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B)


## Dependencies
* :warning: [graph/bellman_ford.hpp](../../../library/graph/bellman_ford.hpp.html)


## Code
```cpp
#include <iostream>
#include <vector>
#include "graph/bellman_ford.hpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

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
    vector<lint> ret = bellman_ford(r, e, V);
    vector<lint> ret2 = bellman_ford(r, e, V + 1);

    for (int i = 0; i < V; i++) {
        if (ret[i] != ret2[i]) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        if (ret[i] == INF) puts("INF");
        else printf("%lld\n", ret[i]);
    }
}
```

[Back to top page](../../../index.html)

