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
#define MOD 1000000007

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

ll Permutation(int n, int r){
    ll ans = 1;
    for (int i = 0; i < r;i++){
        ans *= (n - r);
        ans %= MOD;
    }
    return ans;
}

ll factorial(int n){
    return Permutation(n, n);
}

void solve(){
    int n;
    cin >> n;
    vector<int> x(n), a(n);
    for (int i = 0; i < n;i++)
        cin >> x[i];

    vector<pair<int,int>> b;

    for (int i = 0; i < n;i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < n;i++){
        b.push_back({x[i] - a[0], 1});
        b.push_back({x[i] + a[0], 0});
    }

    sort(b.begin(), b.end());
    int k = 0;

    
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}