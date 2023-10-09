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

int n;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> newMatrix;

void dfs(const int u, const int dist, const int parent, const int s) {
    for (const auto &[v, w] : adj[u])
        if (v != parent) {
            newMatrix[s][v] = newMatrix[v][s] = min(newMatrix[s][v], dist + w);
            dfs(v, dist + w, u, s);
        }
}

void solve() {
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<tuple<int, int, int>> edgeList;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            edgeList.push_back({matrix[i][j], i, j});
        }

    sort(all(edgeList));

    UnionFind dsu(n);
    adj.assign(n, vector<pair<int, int>>());
    for (const auto &[w, u, v] : edgeList) {
        if (!dsu.equivalence(u, v)) {
            dsu.unite(u, v);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    newMatrix.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dfs(i, 0, -1, i);

    for (int i = 0; i < n; i++)
        newMatrix[i][i] = 0;

    if (n != 1 && matrix == vector<vector<int>>(n, vector<int>(n, 0)))
        cout << "NO\n";
    else if (matrix != newMatrix)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}