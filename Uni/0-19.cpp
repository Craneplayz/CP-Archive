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
    int n;
    string s;
    cin >> n >> s;

    map<string, int> table;
    map<string, int> nGram2Id;
    int idNGram = 0;
    string nGram = "";

    for (int i = 0; i < (int)s.length(); i++) {
        nGram += s[i];
        if ((int)nGram.length() == n) {
            table[nGram]++;
            if (nGram2Id.find(nGram) == nGram2Id.end())
                nGram2Id[nGram] = idNGram++;
            nGram = nGram.substr(1);
        }
    }

    int max = 0;
    vector<pair<int, string>> ans;
    for (auto [nGram, cnt] : table)
        if (cnt >= max) {
            if (cnt > max)
                ans.clear();

            max = cnt;
            ans.push_back({nGram2Id[nGram], nGram});
        }

    if (max == 1) {
        cout << "NO\n";
        return;
    }

    sort(all(ans));
    cout << max << '\n';
    for (auto [_, nGram] : ans)
        cout << nGram << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}