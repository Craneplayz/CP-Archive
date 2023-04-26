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

int ans = 0;
vector<int> d;
vector<vector<int>> a;

void bfs(int s){
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < (int)a[x].size(); i++){
            int y = a[x][i];
            if (d[y])
                continue;
            else {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    a.assign(n + 1, vector<int>());
    d.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        a[x].push_back(i+2);
    }
    bfs(1);
    vector<int> K(n + 1, 0);
    for (int i = 0; i < n;i++){
        K[d[i + 1]] = (K[d[i+1]] + 1) & 1;
    }
    int ans = 0;
    for (int i = 0; i < (int)K.size();i++){
        ans += K[i];
    }
    cout << ans << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}