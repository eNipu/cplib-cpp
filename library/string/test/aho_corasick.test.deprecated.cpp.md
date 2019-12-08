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


# :warning: string/test/aho_corasick.test.deprecated.cpp
* category: string/test


[Back to top page](../../../index.html)



## Dependencies
* :warning: [string/aho_corasick.hpp](../aho_corasick.hpp.html)


## Code
```cpp
#include <bitset>
#include <iostream>
#include "string/aho_corasick.hpp"
using namespace std;
#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D

void operator+=(bitset<10000> &l, const bitset<10000> &r) { l |= r; }

int main()
{
    Trie<bitset<10000>> trie;
    string T;
    cin >> T;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string P;
        cin >> P;
        bitset<10000> bs;
        bs.set(i);
        trie.add_keyword(P, bs);
    }
    trie.build_aho_corasick();

    int now = 0;
    bitset<10000> ans;
    for (auto c : T)
    {
        while (now and trie.child[now][c] == 0) now = trie.fail[now];
        now = trie.child[now][c];
        ans |= trie.node_info[now];
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
}

```

[Back to top page](../../../index.html)

