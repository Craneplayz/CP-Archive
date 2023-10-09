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

// 准备一个叫作 `_Child` 的 Struct
// 把`Child`当成这个Struct的Alias，再把他的Pointer用`ChildPtr` 来命名
typedef struct _Child {
    int id = -1;
    struct _Child *next;
} Child, *ChildPtr;

ChildPtr initChildren(const int n) {
    ChildPtr head = (ChildPtr)malloc(sizeof(Child));
    head->id = 1;
    ChildPtr curr = head, prev = head; // Assign pointer, prev和head指向同一个地址
    for (int i = 2; i <= n; i++) {
        curr = (ChildPtr)malloc(sizeof(Child));
        curr->id = i;
        prev->next = curr;
        prev = curr;
    }
    curr->next = head;
    return head;
}

void solve() {
    string s;
    cin >> s;
    vector<int> S;
    string x = "";
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == ',') {
            S.push_back(stoi(x));
            x = "";
        } else {
            x += s[i];
        }

        if (i == (int)s.length() - 1)
            S.push_back(stoi(x));
    }

    int n = S[0], m = S[1], k = S[2];

    ChildPtr child = initChildren(n);
    ChildPtr prev = child, removed = NULL;

    for (int i = 0; i < k;) {
        for (int j = 1; j <= m; j++) {
            if (j == m) {
                prev->next = child->next;
                removed = child;
                i++;
            } else {
                prev = child;
            }
            child = prev->next;
        }
    }

    cout << removed->id << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}