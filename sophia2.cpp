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

struct Person {
    string sex;
    double height;
} people[41];

bool cmp(const Person &a, const Person &b) {
    if (a.sex == b.sex) // Compare by height if the sex of both people are the same
        if (a.sex == "male")
            return a.height < b.height; // Sort by height ascending if sex is "male"
        else
            return a.height > b.height; // Sort by height ascending if sex is "female"
    else
        // Returns `true` when `sex` is male, allows `male Person` to be sorted first in the result array
        return a.sex == "male"; // b.sex == "female"
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> people[i].sex >> people[i].height;

    sort(people, people + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << people[i].height;
        if (i != n - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}