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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> d(n, INF);
    // Probability of nodes getting visited
    vector<double> p(n, 0);
    vector<int> leaves;

    // BFS
    queue<int> q;
    d[0] = 0;
    p[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int m = adj[u].size();

        int unvisitedCount = count_if(all(adj[u]), [&d](const int &v) {
            return d[v] == INF;
        });

        bool hasChild = false;
        for (const int &v : adj[u]) {
            if (d[v] == INF) { // Vertex yet to be visited
                q.push(v);
                d[v] = d[u] + 1;
                p[v] = p[u] / unvisitedCount;
                hasChild = true;
            }
        }

        if (!hasChild) // This vertex is a leaf
            leaves.push_back(u);
    }

    double ans = 0;
    for (const int &leaf : leaves)
        ans += d[leaf] * p[leaf];

    cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}