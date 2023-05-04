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
#include <unordered_set>
using namespace std;

#define ll long long
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve() {
    int n;
    for (int T = 1; cin >> n; T++) {
        vector<int> busyness(n); // 0-th based
        for (int i = 0; i < n; i++)
            cin >> busyness[i];

        int m;
        cin >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            int w = busyness[v - 1] - busyness[u - 1];
            adj[u].push_back({v, w * w * w});
        }

        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        unordered_set<int> hashSet;
        // Complying to negative circle
        for (int V = 0; V < 2*n; V++) {
            bool costChanged = false;
            for (int u = 1; u <= n; u++)
                for (int i = 0; i < (int)adj[u].size() && dist[u] != 1e9; i++) {
                    int v = adj[u][i].first, w = adj[u][i].second;
                    if (dist[u] + w < dist[v]) {
                        if (V >= n)
                            hashSet.insert(v);
                        dist[v] = dist[u] + w;
                        costChanged = true;
                    }
                }
            if (!costChanged)
                break;
        }

        cout << "Set #" << T << '\n';

        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            if (hashSet.count(x) || dist[x] < 3 || dist[x] == 1e9 || x == 1)
                cout << '?' << '\n';
            else
                cout << dist[x] << '\n';
        }
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