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
    string a, b;
    cin >> a >> b;
    const int n = a.length(), m = b.length();

    // dp[i][j] = edit distance to transform prefix of a with length i
    // to prefix of b with length j
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // Remove 1 character
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // Add 1 character
            if (i && j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])); // Match & Modify
        }

    cout << dp[n][m] << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}