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
    long long n, W;
    cin >> n >> W;
    const long long target = (W + 1) >> 1;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[i] = {x, i + 1};
    }

    sort(all(a));
    vector<int> ans;
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (sum + a[i].first > W)
            continue;
        sum += a[i].first;
        ans.push_back(a[i].second);

        if (sum >= target)
            break;
    }

    if (!(target <= sum && sum <= W))
        cout << "-1\n";
    else {
        cout << ans.size() << '\n';
        sort(all(ans));
        for (int &x : ans)
            cout << x << " ";
        cout << "\n";
    }
}

int main() {
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