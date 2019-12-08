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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# ライブラリの HTML ビルドテスト

ここに書いた内容がトップページに足されます

* this unordered seed list will be replaced by toc as unordered list
{:toc}

## Library Files
### binary_lifting(doubling)
* :warning: [binary_lifting(doubling)/doubling.hpp](library/binary_lifting(doubling)/doubling.hpp.html)


### convolution
* :warning: [convolution/fft_mod.hpp](library/convolution/fft_mod.hpp.html)


### convolution/integer_convolution
* :warning: [convolution/integer_convolution/integer_convolution.hpp](library/convolution/integer_convolution/integer_convolution.hpp.html)


### convolution/set_convolution
* :warning: [convolution/set_convolution/zeta_moebius.cpp](library/convolution/set_convolution/zeta_moebius.cpp.html)


### formal_power_series
* :warning: [formal_power_series/formal_power_series.hpp](library/formal_power_series/formal_power_series.hpp.html)


### graph
* :warning: [graph/bellman_ford.hpp](library/graph/bellman_ford.hpp.html)
* :warning: [graph/bipartite-matching.hpp](library/graph/bipartite-matching.hpp.html)
* :warning: [graph/dijkstra.hpp](library/graph/dijkstra.hpp.html)
* :warning: [graph/flow_mincost.hpp](library/graph/flow_mincost.hpp.html)
* :warning: [graph/lowlink.hpp](library/graph/lowlink.hpp.html)


### graph-tree
* :warning: [graph-tree/centroid_decomposition.hpp](library/graph-tree/centroid_decomposition.hpp.html)
* :warning: [graph-tree/lowest_common_ancestor.hpp](library/graph-tree/lowest_common_ancestor.hpp.html)


### linear_algebra_matrix
* :heavy_check_mark: [linear_algebra_matrix/linalg_bitset.hpp](library/linear_algebra_matrix/linalg_bitset.hpp.html)
* :heavy_check_mark: [linear_algebra_matrix/linalg_longlong.hpp](library/linear_algebra_matrix/linalg_longlong.hpp.html)


### linear_algebra_matrix/test
* :warning: [linear_algebra_matrix/test/linalg_longlong.test.deprecated.cpp](library/linear_algebra_matrix/test/linalg_longlong.test.deprecated.cpp.html)


### marathonmatch
* :warning: [marathonmatch/timelimit.cpp](library/marathonmatch/timelimit.cpp.html)


### modulus
* :warning: [modulus/bare_mod_algebra.hpp](library/modulus/bare_mod_algebra.hpp.html)
* :warning: [modulus/modint_fixed.hpp](library/modulus/modint_fixed.hpp.html)
* :warning: [modulus/modint_runtime.hpp](library/modulus/modint_runtime.hpp.html)


### other_data_structures
* :warning: [other_data_structures/sliding_window_aggregation.hpp](library/other_data_structures/sliding_window_aggregation.hpp.html)


### prime
* :warning: [prime/prime.hpp](library/prime/prime.hpp.html)


### random
* :warning: [random/custom_hash.hpp](library/random/custom_hash.hpp.html)
* :warning: [random/rand_nondeterministic.hpp](library/random/rand_nondeterministic.hpp.html)
* :warning: [random/rolling_hash_1d_general.hpp](library/random/rolling_hash_1d_general.hpp.html)
* :warning: [random/xorshift.hpp](library/random/xorshift.hpp.html)


### segmenttree
* :warning: [segmenttree/range_minimum_query.hpp](library/segmenttree/range_minimum_query.hpp.html)


### string
* :warning: [string/aho_corasick.hpp](library/string/aho_corasick.hpp.html)
* :warning: [string/manacher.hpp](library/string/manacher.hpp.html)
* :warning: [string/mp_algorithm.hpp](library/string/mp_algorithm.hpp.html)
* :heavy_check_mark: [string/z_algorithm.hpp](library/string/z_algorithm.hpp.html)


### string/test
* :warning: [string/test/aho_corasick.test.deprecated.cpp](library/string/test/aho_corasick.test.deprecated.cpp.html)
* :warning: [string/test/manacher_mp.test.deprecated.cpp](library/string/test/manacher_mp.test.deprecated.cpp.html)


### unionfind
* :warning: [unionfind/undo_unionfind.hpp](library/unionfind/undo_unionfind.hpp.html)
* :warning: [unionfind/unionfind_plain.hpp](library/unionfind/unionfind_plain.hpp.html)
* :warning: [unionfind/unionfind_sizebased.hpp](library/unionfind/unionfind_sizebased.hpp.html)
* :warning: [unionfind/weighted_unionfind.hpp](library/unionfind/weighted_unionfind.hpp.html)


## Verify Files
* :warning: [formal_power_series/test/bernoulli_number.test.cpp](verify/formal_power_series/test/bernoulli_number.test.cpp.html)
* :heavy_check_mark: [formal_power_series/test/division_number.test.cpp](verify/formal_power_series/test/division_number.test.cpp.html)
* :warning: [formal_power_series/test/fps_exp.test.cpp](verify/formal_power_series/test/fps_exp.test.cpp.html)
* :warning: [formal_power_series/test/fps_exp_modintruntime.test.cpp](verify/formal_power_series/test/fps_exp_modintruntime.test.cpp.html)
* :warning: [formal_power_series/test/fps_inv.test.cpp](verify/formal_power_series/test/fps_inv.test.cpp.html)
* :heavy_check_mark: [formal_power_series/test/fps_log.test.cpp](verify/formal_power_series/test/fps_log.test.cpp.html)
* :heavy_check_mark: [formal_power_series/test/fps_sqrt.test.cpp](verify/formal_power_series/test/fps_sqrt.test.cpp.html)
* :heavy_check_mark: [formal_power_series/test/fps_sqrt_modintruntime.test.cpp](verify/formal_power_series/test/fps_sqrt_modintruntime.test.cpp.html)
* :warning: [graph-tree/test/lca.test.cpp](verify/graph-tree/test/lca.test.cpp.html)
* :warning: [graph/test/articulation_points.test.cpp](verify/graph/test/articulation_points.test.cpp.html)
* :warning: [graph/test/bellman_ford.test.cpp](verify/graph/test/bellman_ford.test.cpp.html)
* :warning: [graph/test/bipartite-matching.test.cpp](verify/graph/test/bipartite-matching.test.cpp.html)
* :warning: [graph/test/bridge.test.cpp](verify/graph/test/bridge.test.cpp.html)
* :warning: [graph/test/dijkstra.test.cpp](verify/graph/test/dijkstra.test.cpp.html)
* :warning: [graph/test/mincostflow.test.cpp](verify/graph/test/mincostflow.test.cpp.html)
* :heavy_check_mark: [linear_algebra_matrix/test/linalg_bitset.test.cpp](verify/linear_algebra_matrix/test/linalg_bitset.test.cpp.html)
* :heavy_check_mark: [linear_algebra_matrix/test/linalg_longlong_matmul.test.cpp](verify/linear_algebra_matrix/test/linalg_longlong_matmul.test.cpp.html)
* :warning: [modulus/test/sqrt_modint_runtime.test.cpp](verify/modulus/test/sqrt_modint_runtime.test.cpp.html)
* :warning: [prime/test/gen_primes.test.cpp](verify/prime/test/gen_primes.test.cpp.html)
* :warning: [random/test/rolling_hash.test.cpp](verify/random/test/rolling_hash.test.cpp.html)
* :warning: [random/test/rolling_hash_w_modint.test.cpp](verify/random/test/rolling_hash_w_modint.test.cpp.html)
* :warning: [segmenttree/test/range_minimum_query.test.cpp](verify/segmenttree/test/range_minimum_query.test.cpp.html)
* :heavy_check_mark: [string/test/z_algorithm.test.cpp](verify/string/test/z_algorithm.test.cpp.html)
* :warning: [unionfind/test/unionfind_plain.test.cpp](verify/unionfind/test/unionfind_plain.test.cpp.html)
* :warning: [unionfind/test/unionfind_sizebased.test.cpp](verify/unionfind/test/unionfind_sizebased.test.cpp.html)
* :warning: [unionfind/test/weighted_unionfind.test.cpp](verify/unionfind/test/weighted_unionfind.test.cpp.html)


