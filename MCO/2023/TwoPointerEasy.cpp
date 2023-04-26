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
    ll n, A, B;
    cin >> n >> A >> B;
    if(A > B)
        swap(A, B);
    vector<ll> centre;
    ll dA = 0, dB = 0;
    for (int i = 0; i < n; i++) {
        int city;
        cin >> city;
        if (city <= A) {
            dA = max(dA, abs(city - A));
        }
        elif (city >= B) {
            dB = max(dB, abs(city - B));
        }
        else{
            centre.push_back(city);
        }
    }
    centre.push_back(A);
    centre.push_back(B);

    sort(centre.begin(), centre.end());

    ll ans = LLONG_MAX;
    for (int i = 0; i < (int)centre.size()-1;i++){
        ll dAC = abs(centre[i] - A);
        ll dBC = abs(centre[i + 1] - B);

        ll opA = min(2 * dA + dAC, dA + 2 * dAC);
        ll opB = min(2 * dB + dBC, dB + 2 * dBC);

        ans = min(ans, opA + opB);
    }

    if(centre.empty())
        ans = min(ans, (ll) dA + dB);

    cout << ans << '\n';
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