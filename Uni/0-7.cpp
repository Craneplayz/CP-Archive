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

int gcd(const int a, const int b) {
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            continue;

        for (int j = i + 1; j < n; j++)
            if (gcd(a[i], a[j]) == 1)
                ans.push_back({a[i], a[j]});
    }

    if (!ans.size()) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i)
            cout << ",";
        cout << ans[i].first << "/" << ans[i].second;
    }
    cout << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}