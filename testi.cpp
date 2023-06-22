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

typedef long long ll;
typedef long double ld;
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e9

class UnionFind {
private:
    int _size, _maxCardinal;
    vector<int> _p, _rank, _cardinal;

public:
    UnionFind(const int n) : _size(n),
                             _p(n),
                             _rank(n),
                             _cardinal(n, 1) {
        iota(_p.begin(), _p.end(), 0);
    }

    int find(const int x) {
        if (_p[x] == x)
            return _p[x];
        else
            return _p[x] = find(_p[x]); // Path Compression
    }

    bool equivalence(const int x, const int y) {
        return find(x) == find(y);
    }

    void unite(const int i, const int j) {
        if (!equivalence(i, j)) {
            int x = find(i), y = find(j);
            _size--;
            if (_rank[x] >= _rank[y]) {
                // 把集合y添加到集合x
                _p[y] = x;
                _cardinal[x] += _cardinal[y];
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                // 把集合x添加到集合y
                _p[x] = y;
                _cardinal[y] += _cardinal[x];
            }
        }
    }

    int size() const {
        return _size;
    }

    int cardinal(const int x) {
        return _cardinal[find(x)];
    }
};