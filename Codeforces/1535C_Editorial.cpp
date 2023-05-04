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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve(){
    string a;
    cin >> a;
    const int n = a.length();

    vector<vector<int>> lst(2, vector<int>(2, -1)); // Counter array to record last occurrences
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int s = a[i] - '0';
        int p = i & 1; // Get Parity
        int l = i - 1; // 最少一个
        if (a[i] != '0') // a[i] == '1' or '?'
            l = min(l, max(lst[1][p ^ 1], lst[0][p])); // 找第一个奇偶性相同的‘0’，或奇偶性不同的‘1’

        if (a[i] != '1') // a[i] == '0' or '?'
            l = min(l, max(lst[0][p ^ 1], lst[1][p])); // 找第一个奇偶性相同的‘1’，或奇偶性不同的‘0'

        ans += i - l;
        
        if (a[i]!='?') // a[i] == '0' or '1'
            lst[s][p] = i; // 更新特定奇偶性的‘s’最后出现的位置
    }
    cout << ans << "\n";
}

int main(){
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