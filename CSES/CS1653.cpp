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
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, long long>> dp((1 << n), {n + 1, INT_MAX});

    dp[0] = {1, 0};

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                pair<int, long long> p = dp[i];

                if (p.second + a[j] > x) {
                    p.first++;
                    p.second = min(p.second,a[j]);
                }
                else
                    p.second += a[j];


                dp[i | (1 << j)] = min(dp[i | (1 << j)], p);
            }
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