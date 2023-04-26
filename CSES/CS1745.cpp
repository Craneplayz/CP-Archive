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

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(2, vector<ll>(m + 1));

    if (!a[0])
        dp[0].assign(m + 1, 1);
    else
        dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (!a[i])
            for (int j = 1; j <= m; j++) {
                dp[1][j] += dp[0][j];
                if (j - 1 >= 1)
                    dp[1][j] += dp[0][j - 1];
                if (j + 1 <= m)
                    dp[1][j] += dp[0][j + 1];
                dp[1][j] %= MOD;
            }
        else {
            // Only a[i] is possible if element is fixed
            dp[1][a[i]] += dp[0][a[i]];
            if (a[i] - 1 >= 1)
                dp[1][a[i]] += dp[0][a[i] - 1];
            if (a[i] + 1 <= m)
                dp[1][a[i]] += dp[0][a[i] + 1];
            dp[1][a[i]] %= MOD;
        }

        dp[0] = dp[1];
        dp[1] = vector<ll>(m + 1);
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[0][i]) % MOD;

    cout << ans << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}