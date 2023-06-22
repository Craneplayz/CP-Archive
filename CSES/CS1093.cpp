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
    int n;
    cin >> n;
    int sum = (n * (n + 1)) >> 1;

    if (sum & 1) {
        cout << 0 << "\n";
        return;
    }
    else
        sum >>= 1;

    vector<ll> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j - i >= 0; j--)
            dp[j] = (dp[j] + dp[j - i]) % (2LL * MOD);

    cout << (dp[sum] >> 1) % MOD << '\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}