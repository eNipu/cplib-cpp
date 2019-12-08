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


# :warning: other_data_structures/sliding_window_aggregation.hpp
* category: other_data_structures


[Back to top page](../../index.html)



## Code
```cpp
#pragma once
#include <algorithm>
#include <stack>
using namespace std;

/*
Sliding-Window Aggregation based queue
- `std::queue`-like data structure with monoid operation
  - Easily generalized to deque
- Each operation is amortized O(1)
- Verification: <https://www.hackerrank.com/contests/tsg-live-4-programming-contest/challenges/tsg-live-4-procon-lcm-interval/submissions/code/1317888077>
- Reference: <https://github.com/NiMiLib/NoshiMochiLibrary/blob/queue_aggregation/lib/data_structure/sequence/queue_aggregation.hpp>
*/
struct SlidingWindowAggregationQueue
{
    using lint = long long;
    using T_VAL = lint;
    using T_PROD = lint;
    T_PROD PROD_ZERO = 1;
    stack<pair<T_VAL, T_PROD>> front_stack, back_stack;
    static inline T_PROD val2prod(const T_VAL &x) { return x; }
    static inline T_PROD merge(const T_PROD &l, const T_PROD &r)
    {
        lint tmp = l * r / __gcd(l, r);
        return min(tmp, 1000000001LL);
    }

    SlidingWindowAggregationQueue() {}
    bool empty() const { return front_stack.empty() and back_stack.empty(); }
    int size() const { return front_stack.size() + back_stack.size(); }
    T_VAL fold_all() const
    {
        if (empty()) return PROD_ZERO;
        else if (front_stack.empty()) return back_stack.top().second;
        else if (back_stack.empty()) return front_stack.top().second;
        else return merge(front_stack.top().second, back_stack.top().second);
    }
    void push(const T_VAL &x)
    {
        if (back_stack.empty()) back_stack.emplace(x, val2prod(x));
        else back_stack.emplace(x, merge(back_stack.top().second, val2prod(x)));
    }
    T_VAL pop()
    {
        if (front_stack.empty())
        {
            front_stack.emplace(back_stack.top().first, val2prod(back_stack.top().first));
            back_stack.pop();
            while (!back_stack.empty())
            {
                T_VAL t = back_stack.top().first;
                front_stack.emplace(t, merge(val2prod(t), front_stack.top().second));
                back_stack.pop();
            }
        }
        T_VAL t = front_stack.top().first;
        front_stack.pop();
        return t;
    }
};

```

[Back to top page](../../index.html)

