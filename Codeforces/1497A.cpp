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
    vector<int> a(100 + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<int> ans1, ans2;
    for (int i = 0; i <= 100; i++) {
        if (a[i])
            ans1.push_back(i);

        if (a[i] > 1)
            for (int j = 0; j < a[i] - 1; j++)
                ans2.push_back(i);
    }

    for (int x : ans1)
        cout << x << ' ';

    for (int x : ans2)
        cout << x << ' ';

    cout << "\n";
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