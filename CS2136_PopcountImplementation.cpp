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

#define __builtin_popcount(x) __libcpp_popcount(x)
#endif


const uint refb[5] = { 
    0b01010101010101010101010101010101,
    0b00110011001100110011001100110011,
    0b00001111000011110000111100001111,
    0b00000000111111110000000011111111,
    0b00000000000000001111111111111111
};

inline int popcount(uint x){
    uint a = x, b;
    for (int i = 0; i < 5; i++) {
        uint p = 1 << i;
        b = (a >> p) & refb[i];
        a &= refb[i];
        a += b;
    }
    return a;
}

int hammingWeight(int x){
    return popcount(x ^ 0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<uint> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = stoi(s, nullptr, 2);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, popcount(a[i] ^ a[j]));
        }

    cout << ans << endl;
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}