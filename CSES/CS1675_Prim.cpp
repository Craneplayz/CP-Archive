#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <list>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define INF 1e9

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

vector<bool> taken;
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void processPrim(int u) {
    taken[u] = true;
    for (const auto& wv : adj[u]) 
        if (!taken[wv.second])
            pq.push(wv);
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        adj[v - 1].push_back({w, u - 1});
    }

    taken.resize(n);
    processPrim(0);
    long long mstCost = 0;
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (!taken[v]) {
            processPrim(v);
            mstCost += w;
        }
    }

    bool isMst = !count(taken.begin(), taken.end(), false);
    if (isMst)
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