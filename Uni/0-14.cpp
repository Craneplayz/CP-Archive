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
    int R, C;
    string s;
    cin >> R >> C;
    cin.ignore();
    getline(cin, s);
    vector<vector<int>> a(R, vector<int>(C));

    vector<int> digits;
    for (char x : s) {
        int y = x - 'A' + 1;
        if (x == ' ') {
            digits.push_back(0);
            digits.push_back(0);
        } else {

            digits.push_back(y / 10);
            digits.push_back(y % 10);
        }
    }

    // i - layer
    int k = 0;
    for (int i = 0; i < (R + 1) / 2 && k < (int)digits.size(); i++) {
        for (int j = i; j < C - i && k < (int)digits.size(); j++)
            a[i][j] = digits[k++];

        for (int j = i + 1; j < R - i && k < (int)digits.size(); j++)
            a[j][C - i - 1] = digits[k++];

        for (int j = (C - 1) - i - 1; j >= i && k < (int)digits.size(); j--)
            a[R - i - 1][j] = digits[k++];

        for (int j = (R - 1) - i - 1; j > i && k < (int)digits.size(); j--)
            a[j][i] = digits[k++];
    }

    for (auto x : a)
        for (auto y : x)
            cout << y;

    cout << endl;
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}