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
#define INF 1e16

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

vector<long long> aux;

template <typename T>
class SegmentTree {
public:
    /// @brief Array representing Segment Tree
    vector<pair<T, int>> _tree;

    /// @brief Constructor
    /// @param a Underlying array
    /// @param factor "1" or "-1"
    SegmentTree(const vector<T> &a, int factor) {
        _factor = factor;
        _n = a.size();
        _tree.assign(4 * _n, {INF, INT_MAX});
        for (int i = 0; i < _n; i++)
            update(i, a[i]);
    }

    /// @brief Point updates an element of the underlying array
    /// @param i Index of underlying array
    /// @param x New value
    void update(const int i, const T x) {
        update(1, 0, _n, i, x);
    }

    /// @brief Range query
    /// @param i Lower bound of the segment, 0-based, inclusive
    /// @param j Upper bound of the segment, 0-based, exclusive
    /// @return Range query of segment
    T query(const int i, const int j) {
        auto q = query(1, 0, _n, i, j);
        return q.first + _factor * q.second;
    }

private:
    /// @brief Length of underlying array
    int _n;
    /// @brief "+1" or "-1"
    int _factor;

    /// @brief Communicative binary operation for segment tree
    /// @param a Node 1
    /// @param b Node 2
    /// @return Minimum of the nodes
    inline pair<T, int> join(const pair<T, int> &a, const pair<T, int> &b) {
        T dpA = a.first + _factor * a.second;
        T dpB = b.first + _factor * b.second;
        return dpA <= dpB ? a : b;
    }

    /// @brief Traverse to the left child of current node
    /// @param p Parent Node
    /// @return Left child's position
    inline int left(const int p) {
        return p << 1;
    }

    /// @brief Traverse to the right child of current node
    /// @param p Parent Node
    /// @return Right child's position
    inline int right(const int p) {
        return (p << 1) + 1;
    }

    /// @brief Point updates an element of the underlying array
    /// @param p Node position in tree
    /// @param L Lower bound in the underlying array, 0-based, inclusive
    /// @param R Upper bound in the underlying array, 0-based, exclusive
    /// @param i Index in the underlying array, 0-based
    /// @param x New value for the element in the underlying array
    void update(int p, int L, int R, const int i, const T x) {
        if (L + 1 >= R) {
            _tree[p] = {x, aux[i]};
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
    pair<T, int> query(int p, int L, int R, const int i, const int j) {
        if (i <= L && R <= j)
            return _tree[p];
        if (R <= i || L >= j)
            return {(long long)INF, INT_MAX};

        int mid = L + ((R - L) >> 1);
        pair<T, int> p1 = query(left(p), L, mid, i, j);
        pair<T, int> p2 = query(right(p), mid, R, i, j);

        return join(p1, p2);
    }
};

template <typename T>
void normalize(vector<T> &a) {
    aux = a;
    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());
    
    for (int i = 0; i < (int) a.size(); i++)
        a[i] = lower_bound(all(aux), a[i]) - aux.begin();
}

void solve() {
    int n;
    cin >> n;
    n += 2;

    vector<long long> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    normalize(t);

    vector<long long> dp(aux.size(), INF);
    dp[t[0]] = 0; // dp[1][t[0]] = 0

    long long constants = 0;

    // Traveling to the left
    SegmentTree<long long> left(dp, 1);
    // Traveling to the right
    SegmentTree<long long> right(dp, -1);

    // Pushing up from dp[i] to dp[i + 1]
    for (int i = 1; i < n - 1; i++) {
        const int x = aux[t[i + 1]];
        const long long constant = abs(aux[t[i]] - x);
        constants += constant;

        long long leftMin = left.query(t[i + 1], dp.size()) - x;
        long long rightMin = right.query(0, t[i + 1]) + x;

        long long minDist = min(leftMin, rightMin);
        left.update(t[i], minDist - constant);
        right.update(t[i], minDist - constant);
    }

    long long leftMin = (*min_element(all(left._tree))).first;
    long long rightMin = (*min_element(all(right._tree))).first;

    long long ans = min(leftMin, rightMin) + constants;
    cout << ans << '\n';
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    solve();

    return 0;
}