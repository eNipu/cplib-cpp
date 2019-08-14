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