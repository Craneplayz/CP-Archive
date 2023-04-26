#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define double long double



void solve(){
    long long k;
    cin >> k;

    long long ans = 1e18;

    long long L = 0, R = sqrt(k) + 1;
    while (L <= R){
        long long mid = L + ((R - L) >> 1);

        if (k <= (mid + 1) * (mid + 1)){
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }

    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}