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
#define INF 1e18

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve() {
    int n;
    cin >> n;
    n += 2;
    vector<long long> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    vector<long long> dp(n, INF);
    dp[0] = 0; // dp[0][0] = 0

    // Skipping between 0-1, initial position
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            // dp[i+1]
            dp[i] = min(dp[i], dp[j] + abs(t[j] - t[i + 1])); // B moved

            dp[j] = dp[j] + abs(t[i] - t[i + 1]); // A moved
        }
    }
    long long ans = *min_element(all(dp));
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