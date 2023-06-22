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

class UnionFind {
private:
    int _numSets;
    vector<int> _p, _rank, _setSize;

public:
    UnionFind(const int n) : _numSets(n),
                             _p(n),
                             _rank(n),
                             _setSize(n, 1) {
        for (int i = 0; i < n; ++i)
            _p[i] = i;
    }

    int find(const int x) {
        if (_p[x] == x)
            return _p[x];
        else
            return _p[x] = find(_p[x]); // Path Compression
    }

    bool isSameSet(const int x, const int y) {
        return find(x) == find(y);
    }

    void unionSet(const int i, const int j) {
        if (!isSameSet(i, j)) {
            int x = find(i), y = find(j);
            _numSets--;
            if (_rank[x] >= _rank[y]) {
                // 把集合y添加到集合x
                _p[y] = x;
                _setSize[x] += _setSize[y];
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                // 把集合x添加到集合y
                _p[x] = y;
                _setSize[y] += _setSize[x];
            }
        }
    }

    int numSets() const {
        return _numSets;
    }

    int sizeofSet(const int x) {
        return _setSize[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<long long, int, int>> edgeList(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList[i] = {w, u - 1, v - 1};
    }
    sort(edgeList.begin(), edgeList.end());

    UnionFind dsu(n);
    long long mstCost = 0;
    for (int i = 0; i < m && dsu.numSets() != 1; i++) {
        auto [w, u, v] = edgeList[i];
        if (!dsu.isSameSet(u, v)) {
            dsu.unionSet(u, v);
            mstCost += w;
        }
    }
    if (dsu.numSets() == 1) 
        cout << mstCost << "\n";
    else
        cout << "IMPOSSIBLE\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}