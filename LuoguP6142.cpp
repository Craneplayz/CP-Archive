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

typedef long long ll;
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1][v - 1] = min(adj[u - 1][v - 1], w);
        adj[v - 1][u - 1] = min(adj[v - 1][u - 1], w);
    }

    vector<vector<int>> dp(n, vector<int>(1024, INF));

    int S = 0;
    for (int i = 0; i < k; i++) {
        int s;
        cin >> s;
        --s;
        S |= (1 << s);
        dp[s][(1 << s)] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1024; j++)
            for (int h = 0; h < 1024; h++)
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h]);

        for (int j = 0; j < n; j++)
            dp[i][j] = min(dp[i][j], dp[j][S] + adj[i][j]);
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[i][S]);

    cout << ans << '\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}