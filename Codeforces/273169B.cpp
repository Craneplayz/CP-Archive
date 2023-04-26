// Codeforces ITMO Pilot Course - Segment Tree Part 1 Problem 2
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
public:
    SegmentTree(const vector<int>& a){
        _n = a.size();
        _tree.assign(4 * _n, INT_MAX);
        _original = a;

        for (int i = 0; i < _n; i++)
            pointUpdate(i, _original[i]);
    }    

    void pointUpdate(int index, int newValue){
        _original[index] = newValue;
        pointUpdate(1, 0, _n - 1, index);
    }

    
    int query(int i, int j){
        return query(1, 0, _n - 1, i, j);
    }

private:
    int _n;
    vector<int> _tree;
    vector<int> _original;

    inline int left(int p){
        return p << 1;
    }

    inline int right(int p){
        return (p << 1) + 1;
    }

    inline int mid(int L, int R){
        return L + ((R - L) >> 1);
    }

    /// @brief updates a value in the original array
    /// @param p index of Segment Tree
    /// @param L Left in array, inclusive
    /// @param R Right in array, inclusive
    /// @param index Index of array
    void pointUpdate(int p, int L, int R, int index){
        

        if (L >= R){
            _tree[p] = _original[index];
            return;
        }

        if (index <= mid(L, R))
            pointUpdate(left(p), L, mid(L, R), index);
        else 
            pointUpdate(right(p), mid(L, R)+1, R, index);

        _tree[p] = min(_tree[left(p)], _tree[right(p)]);
    }

    int query(int p, int L, int R, int i, int j){
        if (R < i || j < L) return INT_MAX;
        if (i <= L && R <= j) return _tree[p];

        int p1 = query(left(p), L, mid(L, R), i, j);
        int p2 = query(right(p), mid(L, R) + 1, R, i, j);

        return min(p1, p2);
    }
};
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree segmentTree(a);

    while (m--){
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1){
            // @x index, 0-based
            // @y new value
            segmentTree.pointUpdate(x, y);
        }
        else{
            cout << segmentTree.query(x, y - 1) << "\n";
        }
    }

}
