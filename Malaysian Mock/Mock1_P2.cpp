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

// Input
int n;
vector<vector<int>> adj;

vector<int> parent;
vector<bool> visited;

// Output
int minDist = 0;
vector<int> result; // Graph after change

void dfs(int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }

    // Node haven't changed
    if (result[u] == u) {
        minDist += 2; // Swap increases total distance by 2

        if (parent[u]) // Not root
            swap(result[u], result[parent[u]]); // Swap current node between child and parent
        else
            swap(result[u], result[adj[u].front()]); // Swap root with first child

    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent.assign(n + 1, 0);
    visited.assign(n + 1, false);

    result.assign(n + 1, 0);
    iota(all(result), 0);

    dfs(1);

    cout << minDist << "\n";
    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
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