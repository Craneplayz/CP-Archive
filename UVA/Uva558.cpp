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

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n, 1e9);

    // Bellman-Ford's - SSSP with Negative Cycle
    for (int V = 0; V < n - 1; V++){
        bool hasChange = 0;
        for (int u = 0; u < n; u++)
            for (const auto& vw : adj[u])
                if (dist[u] + vw.second < dist[vw.first]){
                    dist[vw.first] = dist[u] + vw.second;
                    hasChange = 1;
                }
        if (!hasChange)
            break;
    }

    // Negative Cycle check
    bool hasNegativeCycle = 0;
    for (int u = 0; u < n && !hasNegativeCycle; u++)
        for (const auto& vw : adj[u])
            if (dist[u] + vw.second < dist[vw.first]) {
                hasNegativeCycle = 1;
                break;
            }
    
    if (hasNegativeCycle)
        cout << "possible\n";
    else
        cout << "not possible\n";
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}