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


# :warning: string/mp_algorithm.hpp
* category: string


[Back to top page](../../index.html)



## Required
* :warning: [string/test/manacher_mp.test.deprecated.cpp](test/manacher_mp.test.deprecated.cpp.html)


## Code
```cpp
#pragma once
#include <string>
#include <vector>


std::vector<int> mp_algorithm(std::string s) {
    int N = s.length();
    std::vector<int> ret(N + 1, -1);
    int j = -1;
    for (int i = 0; i < N;  i++) {
        while (j >= 0 and s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}

```

[Back to top page](../../index.html)

