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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0, sum = accumulate(a.begin(), a.begin() + k + 1, 0);
    for (int i = k; i >= 1; i--) {
        int j = n - (k - i);
        sum += a[j] - a[i];
        ans = max(ans, sum);
    }

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