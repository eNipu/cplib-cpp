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


# :warning: linear_algebra_matrix/linalg_longlong.hpp
* category: linear_algebra_matrix


[Back to top page](../../index.html)



## Required
* :warning: [linear_algebra_matrix/test/linalg_longlong.test.deprecated.cpp](test/linalg_longlong.test.deprecated.cpp.html)


## Verified
* :heavy_check_mark: [linear_algebra_matrix/test/linalg_longlong_matmul.test.cpp](../../verify/linear_algebra_matrix/test/linalg_longlong_matmul.test.cpp.html)


## Code
```cpp
#pragma once
#include <cstdlib>
#include <vector>
using namespace std;
using lint = long long int;

// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
vector<vector<lint>> gauss_jordan(vector<vector<lint>> mtr, lint mod)
{
    // Gauss-Jordan elimination 行基本変形のみを用いるガウス消去法
    int H = mtr.size(), W = mtr[0].size(), c = 0;
    for (int h = 0; h < H; h++)
    {
        if (c == W) break;
        int piv = -1;
        for (int j = h; j < H; j++) if (mtr[j][c]) {
            if (piv == -1 or abs(mtr[j][c]) > abs(mtr[piv][c])) piv = j;
        }
        if (piv == -1) { c++; h--; continue; }
        swap(mtr[piv], mtr[h]);
        if (h != piv) {
            for(int w = 0; w < W; w++) {
                mtr[piv][w] = mtr[piv][w] ? mod - mtr[piv][w] : 0; // 行列式符号不変
            }
        }
        lint pivinv = mod_inverse(mtr[h][c], mod);
        for (int hh = h + 1; hh < H; hh++) {
            for (int w = W - 1; w >= c; w--) {
                mtr[hh][w] = (mtr[hh][w] - mtr[h][w] * mtr[hh][c] % mod * pivinv % mod + mod) % mod;
            }
        }
        c++;
    }
    return mtr;
}

int rank_gauss_jordan(const vector<vector<lint>> &mtr) // Rank of Gauss-Jordan eliminated matrix
{
    for (int h = (int)mtr.size() - 1; h >= 0; h--) {
        for (auto v : mtr[h]) if (v) return h + 1;
    }
    return 0;
}

lint mod_determinant(vector<vector<lint>> mtr, lint mod)
{
    lint ans = 1;
    mtr = gauss_jordan(mtr, mod);
    for (int i = 0; i < (int)mtr.size(); i++) ans = ans * mtr[i][i] % mod;
    return ans;
}

vector<vector<lint>> matmul(const vector<vector<lint>> &A, const vector<vector<lint>> &B, lint mod)
{
    int H = A.size(), W = B[0].size(), K = B.size();
    vector<vector<lint>> C(H, vector<lint>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < K; k++) {
                (C[i][j] += A[i][k] * B[k][j]) %= mod;
            }
        }
    }
    return C;
}

vector<lint> matmul(const vector<vector<lint>> &A, const vector<lint> &v, lint mod)
{
    vector<lint> res(A.size());
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) {
            (res[i] += A[i][j] * v[j]) %= mod;
        }
    }
    return res;
}
vector<vector<lint>> matpower(vector<vector<lint>> X, lint n, lint mod)
{
    vector<vector<lint>> res(X.size(), vector<lint>(X.size()));
    for (int i = 0; i < (int)res.size(); i++) res[i][i] = 1;
    while (n)
    {
        if (n & 1) res = matmul(res, X, mod);
        X = matmul(X, X, mod); n >>= 1;
    }
    return res;
}

```

[Back to top page](../../index.html)

