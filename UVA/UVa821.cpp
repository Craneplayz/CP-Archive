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
#include <numeric>
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
    int a0, b0, t = 0;
    while (cin >> a0 >> b0) {
        if (!a0 && !b0)
            break;

        unordered_set<int> hashSet;
        hashSet.insert(a0);
        hashSet.insert(b0);

        t++;
        cout << "Case " << t << ": average length between pages = ";

        vector<int>
            a = {a0},
            b = {b0};

        int ai, bi;
        while (cin >> ai >> bi) {
            if (!ai && !bi)
                break;
            hashSet.insert(ai);
            hashSet.insert(bi);
            a.push_back(ai);
            b.push_back(bi);
        }

        const int V = hashSet.size();

        vector<vector<int>> adj(101, vector<int>(101, INF));

        for (int i = 0; i < (int)a.size(); i++)
            adj[a[i]][b[i]] = 1;

        for (int k = 1; k <= 100; k++)
            for (int i = 1; i <= 100; i++)
                for (int j = 1; j <= 100; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        double sum = 0;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                if (i != j && adj[i][j] != INF)
                    sum += adj[i][j];

        cout << fixed << setprecision(3) << sum / (V * V - V);

        cout << " clicks" << endl;
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