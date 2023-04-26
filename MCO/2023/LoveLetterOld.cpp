#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

#define EPS 1e-9
#define PI acos(-1)
#define MOD = 1000000009 + 7

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

class UnionFind {
private:
    int _numSets;
    vector<int> _p, _rank, _setSize;

public:
    UnionFind(int n) {
        _p.assign(n, 0);
        _rank.assign(n, 0);
        _setSize.assign(n, 1);
        _numSets = n;
        for (int i = 0; i < n; i++)
            _p[i] = i;
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
        if (_p[x] == x)
            return x;
        return _p[x] = find(_p[x]);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = find(i), y = find(j);
            if (_rank[x] >= _rank[y]) {
                _p[y] = _p[x];
                _setSize[y] += _setSize[x];
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                _p[x] = _p[y];
                _setSize[x] += _setSize[y];
            }
            _numSets--;
        }
    }

    int numDisjointSets() {
        return _numSets;
    }

    int sizeOfSet(int x) {
        return _setSize[find(x)];
    }
};

int as;
vector<pair<int, int>> a;
map<int, int> m1a, m1b; // Connects height to dragonId

map<int, int> m2; // Connetcs height to index
vector<int> p;
vector<vector<int>> pdsu;
vector<ll> d;
UnionFind unionFind(0);
vector<bool> b;

int n, k;

void dijkstra(int s) { //s: height
    d[s] = 0;
    p[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, m1b[s]}); //delta, height
    while(!pq.empty()){
        pair<int, int> front = pq.top();
        pq.pop();

        ll du = front.first;
        int u = front.second; //height in

        if (du > d[u])
            continue; // important check

        // Id in sorted "a"
        int prevId = m2[u] - 1;
        int nextId = m2[u] + 1;
        if (prevId >= 0){
            int prevHeight = a[prevId].first;
            int dragon = m1a[prevHeight];


            int weight = abs(a[m2[u]].first - prevHeight);
            if (d[m1a[u]] + weight <d[dragon]){
                d[dragon] = d[m1a[u]] + weight;
                pq.push({weight, prevHeight});
            }
        }

        if (nextId < n) {
            int nextHeight = a[nextId].first;
            int dragon = m1a[nextHeight];

            int weight = abs(a[m2[u]].first - nextHeight);

            if (d[m1a[u]] + weight < d[dragon]) {
                d[dragon] = d[m1a[u]] + weight;
                pq.push({weight, nextHeight});
            }
        }

        int dragonId = m1a[u];
        int pDragon = unionFind.find(dragonId);
        if (b[pDragon])
            continue;

        b[pDragon] = true;
        for (int i = 0; i < (int)pdsu[pDragon].size(); i++) {
            int dragon = pdsu[pDragon][i];
            pq.push({0, m1b[dragon]});
            pq.push({0, m1b[pDragon]});
        }
    }
}

void solve(){
    cin >> n >> k;
    int evirirHeight;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m1a[x] = i + 1;
        m1b[i + 1] = x;
        a.push_back({x, i + 1});
        if (!i){
            evirirHeight = x;
        }
    }
    sort(a.begin(), a.end());

    UnionFind unionFind = UnionFind(n + 1);
    for (int i = 0; i < k;i++){
        int u, v;
        cin >> u >> v;
        unionFind.unionSet(u, v);
    }

    for (int i = 0; i < n;i++){
        m2[a[i].first] = i; // height is saved in map
    }

    pdsu.assign(n+1, vector<int>());
    for (int i = 0; i < n; i++){
        int parent = unionFind.find(i + 1);

        if (parent != i + 1)
            pdsu[parent].push_back(i + 1);
    }

    d.assign(n + 1, INT_MAX);
    b.assign(n + 1, false);
    dijkstra(1);

    for (int x: d)
        cout << x << " ";

    cout << "\n";
}

int main(){
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    solve();
    
    return 0;
}