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
#include <numeric>
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
    string s;
    cin >> s;
    int n = s.length();

    // dp[i][k] =  # of beautiful substring when the {i}-th element is {k} 
    // given that the length of prefix is {i + 1}
    // k: 0 or 1
    vector<ll> dp(n, 1);

    vector<int> a(n, -1);

    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            dp[i] += dp[i - 1];

            if (s[i-1] == '?'){
                a[i] = a[i - 1];
            }
            else{
                a[i] = i - 1;
            }
        }
        elif (s[i]!=s[i-1]){
            if (s[i-1] == '?' && a[i-1] != -1) {
                int j = a[i - 1];
                int len = i - j - 1;
                if ((len&1)){
                    if(s[i]==s[j])
                        dp[i] += dp[i - 1];
                    else
                        dp[i] += dp[i - 1] - dp[j];
                }
                else{
                    if(s[i]!=s[j])
                        dp[i] += dp[i - 1];
                    else
                        dp[i] += dp[i - 1] - dp[j];
                }

            } else
                dp[i] += dp[i - 1];

            a[i] = i - 1;
        }
        else a[i] = i - 1;

        ans += dp[i];
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