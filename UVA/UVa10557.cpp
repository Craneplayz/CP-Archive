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
#include <unordered_set>
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
#define INF 1e9

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

void solve() {
    int n;
    while (cin >> n) {
        if (n == -1)
            return;

        vector<int> doorEnergy(n + 1);
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<vector<int>> adjRev(n + 1);
        for (int u = 1; u <= n; u++) {
            int m;
            cin >> doorEnergy[u] >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                // adj[u].push_back({v, 0});
                adjRev[v].push_back(u);
            }
        }

        for (int v = 1; v <= n; v++)
            for (const int &u : adjRev[v])
                adj[u].push_back({v, doorEnergy[v]});

        vector<int> visited(n + 1), energy(n + 1, -INF);
        vector<bool> inQueue(n + 1);
        energy[1] = 100;
        inQueue[1] = true;
        queue<int> q({1});
        unordered_set<int> hSet;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            visited[u]++;
            if (visited[u] >= n) {
                hSet.insert(u);
            }
            if (visited[u] == 2 * n)
                break;

            for (const auto &vw : adj[u]) {
                int v = vw.first, w = vw.second;
                if (energy[u] + w > energy[v] && energy[u] + w > 0) {
                    energy[v] = energy[u] + w;
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        bool isPositiveCycled = 0;
        if (hSet.size()) {
            visited.assign(n + 1, 0);
            queue<int> qReversed({n});
            while (!qReversed.empty()) {
                int u = qReversed.front();
                qReversed.pop();
                visited[u] = true;
                if (visited[u] && hSet.find(u) != hSet.end()) {
                    isPositiveCycled = true;
                    break;
                }
                for (const int &v : adjRev[u])
                    if (!visited[v])
                        qReversed.push(v);
            }
        }

        if (isPositiveCycled || energy[n] > 0)
            cout << "winnable\n";
        else
            cout << "hopeless\n";
    }
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}