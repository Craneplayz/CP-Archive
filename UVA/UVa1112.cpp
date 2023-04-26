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

vector<int> d;
vector<vector<pair<int, int>>> adj; // Adjacency List, adj[u] = {w, v}

void dijkstra(int s) {
    d[s] = 0;
    set<pair<int, int>> S;
    S.insert({0, s});
    while (!S.empty()) {
        auto front = *S.begin();
        S.erase(S.begin());
        int du = front.first, u = front.second;

        if (du > d[u])
            continue;

        for (int i = 0; i < (int)adj[u].size(); i++) {
            int w = adj[u][i].first, v = adj[u][i].second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                S.insert(adj[u][i]);
            }
        }
    }
}

void solve() {
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    adj.assign(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[b].push_back({t, a}); // Assuming mice need to get from destination to initial location
    }
    d.assign(N + 1, INT_MAX);
    dijkstra(E);

    cout << count_if(d.begin(), d.end(), [&T](int &x) { return x <= T; }) << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t)
            cout << endl;
    }

    return 0;
}