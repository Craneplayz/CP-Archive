#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

#define ll long long
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e9

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

// class UnionFind {
// private:
//     int _n, _maxSize;
//     vector<int> _p, _rank, _sizeSet;

// public:
//     /// @brief Constructor
//     /// @param n Number of elements in DSU
//     explicit UnionFind(const int n) : _n(n),
//                                       _maxSize(1),
//                                       _p(n + 1),
//                                       _rank(n + 1),
//                                       _sizeSet(n + 1, 1) {}

//     int find(int x) {
//         if (!_p[x])
//             return x;
//         return _p[x] = find(_p[x]);
//     }

//     /// @brief Check the equivalence of two set
//     /// @note Path compression applied
//     /// @param i First element, 0-based
//     /// @param j Second element, 1-based
//     /// @return TRUE if equivalent, FALSE if vice versa
//     bool isSameSet(const int i, const int j) {
//         return find(i + 1) == find(j + 1);
//     }

//     /// @brief Union two sets into one
//     /// @param i Element representing the first set
//     /// @param j Element representing the second set
//     void unite(const int i, const int j) {
//         int x = find(i + 1), y = find(j + 1);
//         if (!isSameSet(x - 1, y - 1)) {
//             if (_rank[x] >= _rank[y]) {
//                 _p[y] = x;
//                 _maxSize = max(_maxSize, _sizeSet[x] += _sizeSet[y]);
//                 if (_rank[x] == _rank[y])
//                     _rank[x]++;
//             } else {
//                 _p[x] = y;
//                 _maxSize = max(_maxSize, _sizeSet[y] += _sizeSet[x]);
//             }
//             _n--;
//         }
//     }

//     /// @brief Getter for number of disjoint sets
//     /// @return Number of disjoint sets
//     int numSets() const {
//         return _n;
//     }

//     int maxSize() const {
//         return _maxSize;
//     }

//     /// @brief Get size of a specific disjoint set
//     /// @param i Element that belongs to the disjoint set of interest
//     /// @return Size of disjoint set of interest
//     int sizeOfSet(const int i) {
//         return _sizeSet[find(i + 1)];
//     }
// };

class UnionFind {
private:
    int _size, _maxCardinal;
    vector<int> _p, _rank, _cardinal;

public:
    /// @brief Constructor
    /// @param n Number of elements
    explicit UnionFind(const int n) : _size(n),
                                      _maxCardinal(1),
                                      _p(n),
                                      _rank(n),
                                      _cardinal(n, 1) {
        iota(_p.begin(), _p.end(), 0);
    }

    /// @brief Find the parent in a disjoint set
    /// @note Path compression applied
    /// @param x Element in the queried set, 0-base
    /// @return Parent in the disjoint set
    int find(const int x) {
        if (_p[x] == x)
            return _p[x];
        else
            return _p[x] = find(_p[x]); // Path Compression
    }

    /// @brief Check if two elements belong to the same set
    /// @param x First element, 0-base
    /// @param y Second element, 0-base
    /// @return TRUE if two elements belong to the same set, FALSE if vice versa
    bool equivalence(const int x, const int y) {
        return find(x) == find(y);
    }

    /// @brief Union two sets
    /// @param i An element in the first set, 0-base
    /// @param j An element in the second set, 0-base
    void unite(const int i, const int j) {
        if (!equivalence(i, j)) {
            int x = find(i), y = find(j);
            _size--;
            if (_rank[x] >= _rank[y]) {
                // 把集合y添加到集合x
                _p[y] = x;
                _cardinal[x] += _cardinal[y];
                _maxCardinal = max(_maxCardinal, _cardinal[x]);
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                // 把集合x添加到集合y
                _p[x] = y;
                _cardinal[y] += _cardinal[x];
                _maxCardinal = max(_maxCardinal, _cardinal[y]);
            }
        }
    }

    /// @brief Getter function
    /// @return Number of disjoint sets in the DSU
    int size() const {
        return _size;
    }


    /// @brief Get the number of elements in a specific set
    /// @param x Element in this disjoint set, 0-base
    /// @return Number of elements in this set
    int cardinal(const int x) {
        return _cardinal[find(x)];
    }

    /// @brief Getter function
    /// @return Maximum cardinal in the DSU
    int maxCardinal() const {
        return _maxCardinal;
    }

    /// @brief Check if specific set contains only one element
    /// @param x Element in this disjoint set, 0-base
    /// @return TRUE if contains only one element, FAlSE if vice versa
    bool singleton(const int x) {
        return cardinal(x) == 1;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    UnionFind dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1);
        cout << dsu.size() << " " << dsu.maxCardinal() << "\n";
    }
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}