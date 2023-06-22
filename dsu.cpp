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
    vector<int> _p, _rank, _cardinal; // 势

public:
    UnionFind(const int n) : _size(n),
                             _maxCardinal(1),
                             _p(n),
                             _rank(n),
                             _cardinal(n, 1) {
        // iota(_p.begin(), _p.end(), 0);
        for (int i = 0; i < n; i++)
            _p[i] = i;
    }

    // Path Compression 路经压缩
    int find(const int x) {
        if (_p[x] == x)
            return x;
        return _p[x] = find(_p[x]);
    }

    bool equivalence(const int i, const int j) {
        return find(i) == find(j);
    }

    /// @brief
    /// @param i Element of first set
    /// @param j ELement of second set
    void unite(const int i, const int j) {
        if (!equivalence(i, j)) {
            int x = find(i), y = find(j);
            _size--;
            if (_rank[x] >= _rank[y]) {
                // 把y加入x
                _p[y] = x;
                _cardinal[x] += _cardinal[y];
                _maxCardinal = max(_maxCardinal, _cardinal[x]);
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                // 把x加入y
                _p[x] = y;
                _cardinal[y] += _cardinal[x];
                _maxCardinal = max(_maxCardinal, _cardinal[y]);
            }
        }
    }

    int size() const {
        return _size;
    }

    int cardinal(const int x) {
        return _cardinal[find(x)];
    }

    int maxCardinal() const {
        return _maxCardinal;
    }

    bool singleton(const int x) {
        return cardinal(x) == 1;
    }
};

int main() {
    int n;
    cin >> n;
    UnionFind dsu(n);

    dsu.unite(0, 1);
    cout << dsu.equivalence(0, 1) << " " << dsu.find(1) <<'\n';
}