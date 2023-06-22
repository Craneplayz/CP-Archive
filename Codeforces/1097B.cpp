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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> bitmask(1 << n);

    for (int k = 0; k < (int)bitmask.size(); k++)
        for (int i = 0; i < n; i++) {
            if (k & (1 << i))
                bitmask[k] += a[i];
            else
                bitmask[k] -= a[i];

            bitmask[k] += 360; // No effect if +ve, map to +ve if -ve
            bitmask[k] %= 360;
        }

    if (find(all(bitmask), 0) != bitmask.end())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}