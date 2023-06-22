#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <list>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_set>
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

vector<int> ways(1e6 + 1);

void preCompute(){
    vector<vector<long long>> dp(2, vector<long long>(2));

    dp[0][0] = dp[0][1] = 1; // First layer
    for (int i = 1; i <= (int)1e6; i++) {
        ways[i] = (dp[0][0] + dp[0][1]) % MOD;
        dp[1][0] = (2 * dp[0][0] + dp[0][1]) % MOD;
        dp[1][1] = (dp[0][0] + 4 * dp[0][1]) % MOD;
        dp[0] = dp[1];
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ways[n] << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    preCompute();

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}