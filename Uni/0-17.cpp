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
    string s;
    getline(cin, s);

    vector<string> words;
    string word = "";
    for (int i = 0; i < (int)s.length(); i++) {
        if (isalpha(s[i]))
            word += s[i];

        if (s[i] == ' ' || i == (int)s.length() - 1)
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
    }

    int nSpace = count(all(s), ' ');

    int splitSpace = 0, trailingSpace = 0;
    if (words.size() > 1) {
        splitSpace = nSpace / (words.size() - 1);
        trailingSpace = nSpace % (words.size() - 1);
    }

    for (int i = 0; i < (int)words.size(); i++) {
        if (i)
            cout << string(splitSpace, ' ');
        cout << words[i];
    }
    cout << string(trailingSpace, ' ') << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}