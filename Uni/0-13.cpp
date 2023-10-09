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
    const int n = 150;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i) {
            a[j] = (a[j] + 1) % 2;
        }

    bool isNotFirst = false;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (isNotFirst)
                cout << " ";
            cout << "N" << i;
            isNotFirst = true;
        }
    }
    cout << "\n";

    cout << count(a.begin() + 1, a.end(), 1) << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}