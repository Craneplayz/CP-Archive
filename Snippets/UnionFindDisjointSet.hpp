#include <iostream>
#include <vector>
using namespace std;

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