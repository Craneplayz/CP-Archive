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

int n, A, B;
long long ans = LLONG_MAX;
vector<vector<int>> dp;
vector<int> t;

void backtrack(int i, int posA, int posB, long long d){
    if (d >= ans)
        return;
    if (i == (int)t.size()) {
        ans = min(ans, d);
        return;
    }

    backtrack(i + 1, t[i], posB, d + abs(t[i] - posA));

    backtrack(i + 1, posA, t[i], d + abs(t[i] - posB));
}

void solve(){
    cin >> n >> A >> B;
    t.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    backtrack(0, A, B, 0);
    cout << ans << "\n";
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}