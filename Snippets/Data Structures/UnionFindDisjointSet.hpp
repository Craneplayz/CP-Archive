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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_set>
using namespace std;

class UnionFind {
private:
    int _numSets;
    vector<int> _p, _rank, _setSize;

public:
    UnionFind(const int n) : _numSets(n),
                             _p(n),
                             _rank(n),
                             _setSize(n, 1) {
        for (int i = 0; i < n; ++i)
            _p[i] = i;
    }

    int find(const int x) {
        if (_p[x] == x)
            return _p[x];
        else
            return _p[x] = find(_p[x]); // Path Compression
    }

    bool isSameSet(const int x, const int y) {
        return find(x) == find(y);
    }

    void unionSet(const int i, const int j) {
        if (!isSameSet(i, j)) {
            int x = find(i), y = find(j);
            _numSets--;
            if (_rank[x] >= _rank[y]) {
                // 把集合y添加到集合x
                _p[y] = x;
                _setSize[x] += _setSize[y];
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                // 把集合x添加到集合y
                _p[x] = y;
                _setSize[y] += _setSize[x];
            }
        }
    }

    int numSets() const {
        return _numSets;
    }

    int sizeofSet(const int x) {
        return _setSize[find(x)];
    }
};
