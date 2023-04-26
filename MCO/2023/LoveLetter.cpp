#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define ll long long
#define elif else if
#define endl '\n'

#define EPS 1e-9
#define PI acos(-1)
#define MOD = 1000000009 + 7

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
    UnionFind(int n) {
        _p.assign(n, 0);
        _rank.assign(n, 0);
        _setSize.assign(n, 1);
        _numSets = n;
        for (int i = 0; i < n; i++)
            _p[i] = i;
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
        if (_p[x] == x)
            return x;
        return _p[x] = find(_p[x]);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = find(i), y = find(j);
            if (_rank[x] >= _rank[y]) {
                _p[y] = _p[x];
                _setSize[y] += _setSize[x];
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                _p[x] = _p[y];
                _setSize[x] += _setSize[y];
            }
            _numSets--;
        }
    }

    int numDisjointSets() {
        return _numSets;
    }

    int sizeOfSet(int x) {
        return _setSize[find(x)];
    }
};

vector<pair<int, int>> a;
vector<vector<pair<int, int>>> adj;
vector<ll> d;
UnionFind unionFind(0);
vector<bool> b;

void dijkstra(int s) { // s: height
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s}); // delta, height
    while (!pq.empty()) {
        pair<int, int> front = pq.top();
        pq.pop();

        ll du = front.first;
        int u = front.second; // dragonId in

        if (du > d[u])
            continue; // important check

        for (int i = 0; i < (int)adj[u].size(); i++) {
            int w = adj[u][i].first, v = adj[u][i].second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(a.begin(), a.end());

    adj.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u = a[i].second, v = a[i + 1].second;
        int w = abs(a[i].first - a[i + 1].first);

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    UnionFind unionFind = UnionFind(n + 1);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        unionFind.unionSet(u, v);
    }

    for (int i = 0; i < n; i++) {
        int parent = unionFind.find(i + 1);

        if (parent != i + 1) {
            adj[parent].push_back({0, i + 1});
            adj[i + 1].push_back({0, parent});
        }
    }

    d.assign(n + 1, INT_MAX);
    b.assign(n + 1, false);
    dijkstra(1);

    for (int i = 1; i < n + 1; i++)
        cout << d[i] << " ";

    cout << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}