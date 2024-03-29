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
#define INF 1e18

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

int main() {
    // while (true) {
    string t;
    getline(cin, t);

    while (!isdigit(t.front())) {
        t.erase(t.begin());
    }

    for (int i = 0; i < (int)t.length(); i++) {
        if (t[i] == ' ') {
            if ((i && isalnum(t[i - 1])) ||
                (i < (int)t.length() && isalnum(t[i + 1])))
                t[i] = '-';
            else
                t.erase(t.begin() + i--);
        }
    }

    for (int i = 0; i < (int)t.length();i++){
        if (t[i] == '-' && t[i+1] == '-')
            t.erase(t.begin() + i--);
    }

        cout << t << '\n';
    // }
}