// Codeforces ITMO Pilot Course - Segment Tree Part 1 Problem A
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
// Range Sum Query as example
public:
    SegmentTree(vector<long long> a){
        _n = a.size();
        _tree.assign(4 * _n + 1, 0);
        _original.assign(_n, 0);

        // Build Tree
        for (int i = 0; i < _n; i++)
            set(i, a[i]);
        
        _original = a;
    }

    long long query(int i, int j){
        return query(1, 0, _n - 1, i, j);
    }

    void set(int index, int newValue){
        set(1, 0, _n - 1, index, newValue);
        _original[index] = newValue;
    }

private:
    int _n;
    vector<long long> _tree, _original;

    inline int left(int p){
        return p << 1; 
    }

    inline int right(int p){
        return (p << 1) + 1;
    }

    inline int mid(int L, int R){
        return L + ((R - L) >> 1);
    }

    void set(int p, int L, int R, int i, int newValue){
        _tree[p] = _tree[p] + newValue - _original[i];

        if (L >= R) return;

        if (i <= mid(L, R)) 
            set(left(p), L, mid(L, R), i, newValue);
        else 
            set(right(p), mid(L, R) + 1, R, i, newValue);
    }

    long long query(int p, int L, int R, int i, int j){
        if (R < i || j < L) return INT_MIN; //Segment not in query range
        if (i <= L && R <= j) return _tree[p]; // Segment in query range

        
        auto p1 = query(left(p), L, mid(L, R), i, j);
        auto p2 = query(right(p), mid(L, R) + 1, R, i, j);

        if (p1 == INT_MIN) p1 = 0;
        if (p2 == INT_MIN) p2 = 0;

        return p1 + p2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree segmentTree(a);
    while (m--){
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1){
            segmentTree.set(x, y);
        }
        else{
            cout << segmentTree.query(x, y - 1) << '\n';
        }
    }

    return 0;
}