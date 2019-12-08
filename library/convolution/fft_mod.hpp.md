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


# :warning: convolution/fft_mod.hpp
* category: convolution


[Back to top page](../../index.html)



## Required
* :warning: [formal_power_series/formal_power_series.hpp](../formal_power_series/formal_power_series.hpp.html)


## Code
```cpp
#pragma once
#include <vector>
using namespace std;

// Integer FFT (Fast Fourier Transform) for ModInt class
// is_inverse: inverse transform
template <typename MODINT>
void fft_mod(vector<MODINT> &a, bool is_inverse = false)
{
    using lint = long long int;
    int n = a.size();
    assert(__builtin_popcount(n) == 1);
    MODINT h = MODINT(MODINT::get_primitive_root()).power((MODINT::get_mod() - 1) / n);
    if (is_inverse) h = 1 / h;

    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }

    for (int m = 1; m < n; m *= 2) {
        int m2 = 2 * m;
        lint base = h.power(n / m2);
        MODINT w(1);
        for(int x = 0; x < m; x++) {
            for (int s = x; s < n; s += m2) {
                MODINT u = a[s], d = a[s + m] * w;
                a[s] = u + d, a[s + m] = u - d;
            }
            w *= base;
        }
    }
    if (is_inverse)
    {
        lint n_inv = MODINT(n).inv();
        for (auto &v : a) v *= n_inv;
    }
}

// Convolution for ModInt class
// retval[i] = \sum_j a[j] b[i - j]
template <typename MODINT>
vector<MODINT> convolution_mod(vector<MODINT> a, vector<MODINT> b)
{
    int sz = 1, n = a.size(), m = b.size();
    while (sz < n + m) sz <<= 1;
    a.resize(sz), b.resize(sz);
    fft_mod(a, false), fft_mod(b, false);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    fft_mod(a, true);
    a.resize(n + m - 1);
    return a;
}

```

[Back to top page](../../index.html)

