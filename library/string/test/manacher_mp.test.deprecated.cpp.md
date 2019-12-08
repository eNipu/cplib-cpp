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


# :warning: string/test/manacher_mp.test.deprecated.cpp
* category: string/test


[Back to top page](../../../index.html)



## Dependencies
* :warning: [string/manacher.hpp](../manacher.hpp.html)
* :warning: [string/mp_algorithm.hpp](../mp_algorithm.hpp.html)


## Code
```cpp
#include <iostream>
#include <string>
#include <vector>
#include "string/manacher.hpp"
#include "string/mp_algorithm.hpp"
// #define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2934
using namespace std;
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N;
    string T;
    cin >> N >> T;

    vector<int> mp = mp_algorithm(T);
    vector<int> mana = manacher(T);


    int rep = N - mp[N];
    for (int i = 2; i <= N; i++)
    {
        if (i + mana[i - 1] - 1 == N)
        {
            cout << i << endl;
            return 0;
        }
        if (mana[i - 1] < i) continue;
        if ((2 * i - 2) % rep == 0) {
            cout << i << endl;
            return 0;
        }
    }
}
```

[Back to top page](../../../index.html)

