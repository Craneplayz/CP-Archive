#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000009 + 7
#define INF 1e9

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve(){
    int n;
    cin >> n;
    n += 2;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    vector<int> dist(n - 1);
    for (int i = 1; i <= n; i++)
        dist[i - 1] = abs(t[i] - t[i - 1]);

    vector<int> prefixSum(n - 1);
    prefixSum[0] = dist[0];
    for (int i = 1; i < n - 1; i++)
        prefixSum[i] = prefixSum[i - 1] + dist[i];

    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0][1] = dp[1][0] = 0;
    int ans = prefixSum.back();

    dp[2][1] = abs(t[0] - t[2]);
    dp[0][2] = abs(t[1] - t[2]);
    dp[2].back() = dp[2][1] + (prefixSum.back() - prefixSum[1]);
    ans = min(ans, dp[2][1] + (prefixSum.back() - prefixSum[1]));
    ans = min(ans, dp[0][2] + (prefixSum.back() - prefixSum[1]));

    dp[3][2] = dp[0][2] + abs(t[0] - t[3]);
    dp[2][3] = dp[2][1] + abs(t[1] - t[3]);
    dp[6][3] = dp[2][3] + (prefixSum.back() - prefixSum[2]);
    ans = min(ans, dp[3][2] + (prefixSum.back() - prefixSum[2]));
    ans = min(ans, dp[2][3] + (prefixSum.back() - prefixSum[2]));

    for (int i = 4; i < n; i++) {
        dp[i][i - 1] = dp[i - 2][i - 1] + abs(t[i] - t[i - 2]);
        dp[i - 1][i] = dp[i - 1][i - 2] + abs(t[i] - t[i - 2]);

        ans = min(ans, dp[i][i - 1] + (prefixSum.back() - prefixSum[i - 1]));
        dp[i][n - 1] = dp[i][i - 1] + (prefixSum.back() - prefixSum[i - 1]);
        ans = min(ans, dp[i - 1][i] + (prefixSum.back() - prefixSum[i - 1]));
        dp[n-1][i] = dp[i-1][i] + (prefixSum.back() - prefixSum[i - 1]);
    }

    for (auto i:prefixSum)
        cout << i << " ";
    cout << "\n";

    for(auto v:dp){
        for(auto u : v)
            if(u != INF) cout << u << " ";
            else
                cout << "* ";
        cout << "\n";
    }

    cout << ans << "\n";
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}