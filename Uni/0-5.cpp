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

int gcd(const int a, const int b) {
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> q, p;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int id = s.find('/');
        q.push_back(stoi(s.substr(0, id)));
        p.push_back(stoi(s.substr(id + 1)));
    }
    int denominator = accumulate(all(p), 1, [](int a, int b) { return a * b; });
    int numerator = 0;
    for (int i = 0; i < n; i++)
        numerator += denominator * q[i] / p[i];

    int hcf = gcd(numerator, denominator);
    numerator /= hcf;
    denominator /= hcf;

    if (denominator == 1)
        cout << numerator << "\n";
    else
        cout << numerator << "/" << denominator << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}