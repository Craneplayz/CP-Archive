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

typedef long long ll;
typedef long double ld;
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

vector<string> expr;

/// @brief
/// @param x Current index of interest
/// @return { Result of the expression, final index that has been considered}
pair<double, int> eval(const int x = 0) {
    string top = expr[x];
    if (!isalnum(top[0])) { // Symbol is operator
        auto [a, k] = eval(x + 1);

        auto [b, end] = eval(k + 1);

        double res;
        switch (top[0]) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        }

        return {res, end};
    } else {
        return {stof(top), x};
    }
}

int main() {
    string x;
    while (cin >> x)
        expr.push_back(x);

    auto [ans, _] = eval();
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}