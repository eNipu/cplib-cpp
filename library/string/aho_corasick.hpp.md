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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/aho_corasick.hpp
* category: string


[Back to top page](../../index.html)



## Required
* :warning: [string/test/aho_corasick.test.deprecated.cpp](test/aho_corasick.test.deprecated.cpp.html)


## Code
```cpp
#pragma once
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct Trie
{
    vector<map<char, int>> child;
    vector<int> fail;
    vector<T> node_info;
    int root;
    Trie() : child(1), fail(1), node_info(1), root(0) {}
    void add_keyword(string str, T info)
    {
        int now = 0;
        for (auto c : str)
        {
            if (child[now].count(c) == 0)
            {
                child[now][c] = fail.size();
                child.emplace_back(map<char, int>());
                fail.emplace_back(root);
                node_info.emplace_back(0);
            }
            now = child[now][c];
        }
        node_info[now] += info;
    }

    void build_aho_corasick()
    {
        queue<int> q;
        for (auto pa : child[root]) q.push(pa.second);
        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            for (auto pa : child[s])
            {
                int t = fail[s];
                while (t and child[t].count(pa.first) == 0) t = fail[t];
                int u = (child[t].count(pa.first) ? child[t][pa.first] : root);
                fail[pa.second] = u;
                node_info[pa.second] += node_info[u];
                q.push(pa.second);
            }
        }
    }
};

```

[Back to top page](../../index.html)

