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

int n;
vector<vector<int>> adj;
vector<int> d;

double dfs(int u = 0) {
    double sum = 0;

    for (const int& v : adj[u]) {
        if (d[v] == INF) {
            d[v] = d[u] + 1;
            sum += dfs(v);
        }
    }

    // Subtract 1 except when u == 0
    const int m = adj[u].size() - (!!u);
    return m ? sum / m : d[u];
}

void solve(){
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    d.assign(n, INF);
    d[0] = 0;

    cout << fixed << setprecision(9);
    cout << dfs() << "\n";
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}