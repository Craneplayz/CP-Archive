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

vector<vector<int>> adj;

void solve(){
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n;i++)
        sort(all(adj[i]));

    vector<int> tail(n, 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {

        for (int& j : adj[i])
            if (j < i)
                tail[i] = max(tail[i], tail[j] + 1);
            else
                break;

        ans = max(ans, tail[i] * (ll) adj[i].size());
    }
    cout << ans << '\n';
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}