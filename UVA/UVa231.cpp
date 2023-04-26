#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <list>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
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

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

class SegmentTree{
public:
    SegmentTree(vector<int>& a){
        int n = a.size();
        _tree.assign(4*n, -1);
        _a = &a;

        for (int i = 0; i < n; i++)
            pointUpdate(i);
    }

    void pointUpdate(int i) {
        pointUpdate(1, 0, _a->size() - 1, i);
    }

    int query(int i, int j){
        return query(1, 0, _a->size() - 1, i, j);
    }

private:
    vector<int> _tree; // index of dp pointing to result of RMQ
    vector<int> *_a;

    inline int left(const int x){
        return (x << 1);
    }

    inline int right(const int x){
        return (x << 1) + 1;
    }

    void pointUpdate(int p, int L, int R, const int i) {
        if(_tree[p] == -1 || (*_a)[_tree[p]] < (*_a)[i])
            _tree[p] = i;

        if (L >= R)
            return;

        int mid = L + ((R - L) >> 1);

        if (i <= mid)
          pointUpdate(left(p), L, mid, i);
        else
           pointUpdate(right(p), mid + 1, R, i);
    }

    /// @brief Query Operation
    /// @param p Index of Segment Tree
    /// @param L Lower bound represented by Segment Tree
    /// @param R Upper bound represented by Segment Tree
    /// @param i Lower bound of query
    /// @param j Upper bound of query
    /// @return Range Maximum Query, RMQ
    int query(int p, int L, int R, const int i, const int j) {
        // Segment[i, j] not in range [L, R] - Don't Take
        if (j < L || R < i)
           return 0;

        if (i <= L && R <= j) // Node [L, R] fully in range [i, j] - Take
           return _tree[p];

        // [L, R] partially in range [i, j]
        int mid = L + ((R - L) >> 1);
        int p1 = query(left(p), L, mid, i, j); // Traverse to left children
        int p2 = query(right(p), mid + 1, R, i, j); // Traverse to right children

        if ((*_a)[p1] >= (*_a)[p2])
           return p1;
        else
           return p2;
    }
};

void solve(){
    vector<int> a(1);
    for (int I = 1; cin >> a[0]; I++) {
        if(I>1) 
            cout << "\n";
        if (a[0] == -1)
            return;
        if (I > 1)
            cout << "\n";
            
        while (true) {
            int t;
            cin >> t;
            if (t != -1)
                a.push_back(t);
            else
                break;
        }

        const int n = a.size();

        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if(!m.count(a[i]))
                m.insert({a[i], 0});
        }

        // Normalization to [0, n-1]
        for (auto i = m.begin(); i != m.end();i++)
            i->second = m.size() - 1 - distance(m.begin(), i);

        for (int i = 0; i < n;i++)
            a[i] = m[a[i]];

        vector<int> dp(n);
        SegmentTree segmentTree(dp);
        for (int i = 0; i < n; i++){
            int rmq = segmentTree.query(0, a[i]);
            dp[a[i]] = dp[rmq] + 1;
            segmentTree.pointUpdate(a[i]);
        }

        cout << "Test #" << I << ":\n  maximum possible interceptions: ";

        cout<< dp[segmentTree.query(0, n - 1)];
        

        a.clear();
        a.push_back(0);
    }
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}