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

void solve() {
    ll r, c;
    cin >> r >> c;
    ll layer = max(r, c);
    ll upper = layer * layer;
    ll lower = (layer - 1) * (layer - 1);

    if (r >= c) {
        if (r & 1) // Odd Increasing
            cout << lower + c << "\n";
        else
            cout << upper - (c - 1) << '\n';
    } else {
        if (c & 1)
            cout << upper - (r - 1) << "\n";
        else
            cout << lower + r << "\n";
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