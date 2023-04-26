#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <list>
#include <iomanip>
#include <iostream>
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

void solve(){
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    vector<vector<pair<ll,ll>>> dp(2, vector<pair<ll,ll>>(n + 1, {INT_MAX, INT_MAX}));
    vector<vector<pair<ll, ll>>> loc(2, vector<pair<ll, ll>>(n + 1, {INT_MAX, INT_MAX}));

    dp[0][0] = {0, A};
    dp[1][0] = {0, B};
    for (int i = 1; i <= n; i++) {
        int wA = abs(t[i - 1] - dp[0][i-1].second);
        int wB = abs(t[i - 1] - dp[1][i-1].second);

        
        dp[0][i] = {wA + dp[0][i - 1].second, t[i - 1]};
        dp[1][i] = {wB + dp[1][i - 1].second, t[i - 1]};
    }
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}