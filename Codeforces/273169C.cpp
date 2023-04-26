// Codeforces ITMO Pilot Course - Segment Tree Part 1 Problem C
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
public:
    SegmentTree(const vector<int>& a){
        _n = a.size();
        _tree.assign(4 * _n, {INT_MAX, 0});
        _original = a;

        for (int i = 0; i < _n; i++)
            pointUpdate(i, _original[i]);
    }    

    void pointUpdate(int index, int newValue){
        _original[index] = newValue;
        pointUpdate(1, 0, _n - 1, index);
    }

    
    pair<int, int> query(int i, int j){
        return query(1, 0, _n - 1, i, j);
    }

private:
    int _n;
    vector<pair<int, int>> _tree;
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
            _tree[p] = {_original[index], 1};
            return;
        }

        if (index <= mid(L, R))
            pointUpdate(left(p), L, mid(L, R), index);
        else 
            pointUpdate(right(p), mid(L, R)+1, R, index);

        if (_tree[left(p)].first == _tree[right(p)].first)
            _tree[p] = {_tree[left(p)].first, _tree[left(p)].second + _tree[right(p)].second};
        else
            _tree[p] = min(_tree[left(p)], _tree[right(p)]);
    }

    pair<int, int> query(int p, int L, int R, int i, int j){
        if (R < i || j < L) return {INT_MAX, -1};
        if (i <= L && R <= j) return _tree[p];

        pair<int, int> p1 = query(left(p), L, mid(L, R), i, j);
        pair<int, int> p2 = query(right(p), mid(L, R) + 1, R, i, j);

        if (p1.first == p2.first)
            return {p1.first, p1.second + p2.second};
        else
            return min(p1, p2);
    }
};
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0;i < n; i++) cin >> a[i];

    SegmentTree segmentTree(a);
    while (m--){
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1){
            segmentTree.pointUpdate(x, y);
        }
        else{
            auto ans = segmentTree.query(x, y - 1);
            cout << ans.first << " " << ans.second << "\n"; 
        }
    }
}