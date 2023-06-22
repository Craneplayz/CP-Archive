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
    int n, m;
    cin >> n >> m;

    map<string, int> nameId;
    map<int, string> idName;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        nameId[name] = i;
        idName[i] = name;
    }

    vector<vector<bool>> graph(n, vector<bool>(n, 1));
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        int uId = nameId[u], vId = nameId[v];
        graph[uId][vId] = graph[vId][uId] = 0;
    }

    vector<int> bitmask(1 << n, -1);
    bitmask[0] = 0;

    for (int i = 0; i < n; i++)
        for (int k = 0; k < (1 << i); k++) {
            if (!(bitmask[k] >= 0))
                continue;

            bool isConflict = false;
            for (int j = 0; !isConflict && j < i; j++)
                if ((k & (1 << j)) && !graph[i][j])
                    isConflict = true;

            if (isConflict)
                continue;
            else
                bitmask[k + (1 << i)] = bitmask[k] + 1;
        }

    int ans = max_element(all(bitmask)) - bitmask.begin();

    vector<string> names;
    for (int i = 0; i < n; i++)
        if (ans & (1 << i))
            names.push_back(idName[i]);

    sort(all(names));

    cout << names.size() << "\n";
    for (const string &name : names)
        cout << name << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}