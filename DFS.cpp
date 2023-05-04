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

// adj[u] = {v}
// adj[从这个点] = {可以去到的点}
vector<vector<int>> adj = {
    {},     // 0
    {2, 3}, // 1
    {4, 5}, // 2
    {6, 7}, // 3
    {},     // 4
    {},     // 5
    {},     // 6
    {}      // 7
};
vector<bool> visited(11, 0); // Visted array 10 个 False

void dfs(int s) {
    stack<int> stack;
    // let stack = [];
    
    stack.push(1);
    // arr.length
    while (!stack.empty()) {
        int u = stack.top(); 
        stack.pop();
        // let u = stack.pop()
        visited[u] = true;

        // let i = 0; i < adj[u].length; i++
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i]; // let
            if (!visited[v])
                stack.push(v);
        }
    }
}

void solve() {
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}