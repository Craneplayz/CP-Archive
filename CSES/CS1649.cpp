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

class SegmentTree {
public:
    /// @brief Constructor
    /// @param a Underlying array
    SegmentTree(const vector<long long> &a) {
        _n = a.size();
        _tree.assign(4 * _n + 1, INF);
        for (int i = 0; i < _n; i++)
            update(i, a[i]);
    }

    /// @brief Point updates an element of the underlying array
    /// @param i Index of underlying array
    /// @param x New value
    void update(const int i, const int x) {
        update(1, 0, _n, i, x);
    }

    /// @brief Range query
    /// @param i Lower bound of the segment, 0-based, inclusive
    /// @param j Upper bound of the segment, 0-based, exclusive
    /// @return Range query of segment
    long long query(const int i, const int j) {
        return query(1, 0, _n, i, j);
    }

private:
    int _n;
    vector<long long> _tree;

    /// @brief Communicative binary operation for segment tree
    /// @param a Node 1
    /// @param b Node 2
    /// @return Minimum of the nodes
    inline long long join(const int &a, const int &b) {
        return min(a, b);
    }

    inline int left(const int p) {
        return p << 1;
    }

    inline int right(const int p) {
        return (p << 1) + 1;
    }

    /// @brief Point updates an element of the underlying array
    /// @param p Node position in tree
    /// @param L Lower bound in the underlying array, 0-based, inclusive
    /// @param R Upper bound in the underlying array, 0-based, exclusive
    /// @param i Index in the underlying array, 0-based
    /// @param x New value for the element in the underlying array
    void update(int p, int L, int R, const int i, const int x) {
        if (L >= R - 1) {
            _tree[p] = x;
            return;
        }

        int mid = L + ((R - L) >> 1);
        if (i < mid)
            update(left(p), L, mid, i, x);
        else
            update(right(p), mid, R, i, x);

        _tree[p] = join(_tree[left(p)], _tree[right(p)]);
    }

    /// @brief Range query
    /// @param p Node position in tree
    /// @param L Lower bound in the underlying array, 0-based, inclusive
    /// @param R Upper bound in the underlying array, 0-based, exclusive
    /// @param i Lower bound of the segment, 0-based, inclusive
    /// @param j Upper bound of the segment, 0-based, exclusive
    /// @return Range query of segment
    long long query(int p, int L, int R, const int i, const int j) {
        if (i <= L && R <= j)
            return _tree[p];
        if (R <= i || L >= j)
            return INF;

        int mid = L + ((R - L) >> 1);
        long long p1 = query(left(p), L, mid, i, j);
        long long p2 = query(right(p), mid, R, i, j);

        return join(p1, p2);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree segTree(a);

    for (int i = 0; i < q; i++) {
        int x, u, v;
        cin >> x >> u >> v;
        if (x == 1)
            segTree.update(u - 1, v);
        else
            cout << segTree.query(u - 1, v) << "\n";
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