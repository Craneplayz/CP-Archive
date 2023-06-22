#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
public:
    /// @brief Constructor without providing underlying array
    /// @param n Length of underlying array
    /// @param dummy Length of dummy value for underlying array and invalid segments
    SegmentTree(const int n, const int dummy = -1)
        : _n(n), _dummy(dummy) {
        _tree.assign(4 * _n + 1, _dummy);
    }

    /// @brief Constructor
    /// @param a Underlying array
    /// @param dummy Length of dummy value for underlying array and invalid segments
    SegmentTree(const vector<int> &a, const int dummy = -1)
        : _n(a.size()), _dummy(dummy), _tree(4 * _n + 1, dummy) {
        for (int i = 0; i < _n; i++)
            update(i, a[i]);
    }

    /// @brief Point update
    /// @param i Index of underlying array to be updated - (1-th based)
    /// @param val Value to be updated
    void update(const int i, const int val) {
        update(1, 1, _n, i, val);
    }

    /// @brief Query in range [i, j), public wrapper
    /// @param i Lower bound of query segment, inclusive, 1-th based index
    /// @param j Upper bound of query segment, inclusive, 1-th based index
    /// @return Range query
    int query(const int i, const int j) {
        return query(1, 1, _n, i, j);
    }

private:
    const int _n, _dummy;
    vector<int> _tree; // Array constituting the tree

    /// @brief Traverse to left children
    /// @param p Parent's position
    /// @return Left child's position - 2p
    inline int left(const int p) {
        return (p << 1);
    }

    /// @brief Traverse to right child
    /// @param p Parent's position
    /// @return Right child's position - 2p + 1
    inline int right(const int p) {
        return (p << 1) + 1;
    }

    /// @brief Denoting what operation should be used to merge two children
    /// @param x Node 1
    /// @param y Node 2
    /// @return Result of merging
    inline int join(const int x, const int y) {
        return max(x, y);
    }

    /// @brief Point update
    /// @param p Position of current node
    /// @param L Lower bound reprsented by Segment Tree, inclusive, 1-th based index
    /// @param R Upper bound represented by Segment Tree, exclusive, 1-th based index
    /// @param i Index to be updated, 1-th based index
    /// @param val Value to be updated
    void update(int p, int L, int R, const int i, const int val) {
        // Return if L and R only differs by one -
        // segment contains single element
        if (L >= R - 1) {
            _tree[p] = val;
            return;
        }

        int mid = L + ((R - L) >> 1);

        if (i < mid) // Traversing left
            update(left(p), L, mid, i, val);
        else // Traversing right
            update(right(p), mid, R, i, val);

        // Merging result from children
        _tree[p] = join(_tree[left(p)], _tree[right(p)]);
    }

    /// @brief Query in range [i, j)
    /// @param p Position of current node
    /// @param L Lower bound reprsented by Segment Tree, inclusive, 1-th based index
    /// @param R Upper bound represented by Segment Tree, exclusive, 1-th based index
    /// @param i Lower bound of query segment, inclusive, 1-th based index
    /// @param j Upper bound of query segment, inclusive, 1-th based index
    /// @return Range query
    int query(int p, int L, int R, const int i, const int j) {
        // Return default value if segment is entirely out of query range
        if (j <= L || R < i)
            return _dummy;

        // Return value of node if segment is entirely in query range
        if (i <= L && R <= j)
            return _tree[p];

        // Traverse to node's children if segment is partially in query range
        int mid = L + ((R - L) >> 1);
        int node1 = query(left(p), L, mid, i, j);
        int node2 = query(right(p), mid, R, i, j);

        // Merging results from children
        return join(node1, node2);
    }
};