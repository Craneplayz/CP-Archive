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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> dp((1 << n), {INF, INT_MAX});

    dp[0] = {1, 0};

    for (int i = 0; i < n; i++)
        dp[1 << i] = {1, a[i]};

    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < i; j+= i & (-i)) {
            auto [ride1, w1] = dp[j];
            auto [ride2, w2] = dp[i & (~j)];
            pair<int, int> p = {ride1 + ride2, min(w1, w2)};
            if (w1 + w2 <= x) {
                p.first--;
                p.second = w1 + w2;
            }
            dp[i] = min(dp[i], p);
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}