// Sample Problem for meet-in-the-middle
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

#define EPS 1e-9
#define PI acos(-1)
#define MOD = 1000000009 + 7

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

int n, x;
vector<vector<int>> a(2), b(2);

void subsetSum(int n, int sum, int half) {
    if (sum > x)
        return;
    else if (sum == x || n == (int) a[half].size()) {
        b[half].push_back(sum);
        return;
    }

    // Not Taking n-th
    subsetSum(n + 1, sum, half);

    // Taking n-th
    subsetSum(n + 1, sum + a[half][n], half);
}

void solve() {
    cin >> n >> x;
    a[0] = vector<int>((n + 1) >> 1, 0);
    a[1] = vector<int>(n >> 1, 0);

    for (int i = 0; i < (int)a[0].size(); i++)
        cin >> a[0][i];
    for (int i = 0; i < (int)a[1].size(); i++)
        cin >> a[1][i];

    subsetSum(0, 0, 0);
    subsetSum(0, 0, 1);

    sort(b[0].begin(), b[0].end());
    sort(b[1].begin(), b[1].end());

    ll ans = 0;
    for (int i = 0; i < (int)b[0].size(); i++) {
        ans += upper_bound(b[1].begin(), b[1].end(), x - b[0][i]) - lower_bound(b[1].begin(), b[1].end(), x - b[0][i]);
    }

    cout<<ans<<'\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}