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

class UnionFind {
private:
    int _numSets;
    vector<int> _p, _rank, _setSize;

public:
    UnionFind(int n) : _p(n),
                       _rank(n),
                       _setSize(n, 1),
                       _numSets(n) {
        for (int i = 0; i < n; ++i)
            _p[i] = i;
    }

    int find(int x) {
        if (_p[x] == x)
            return _p[x];
        else
            return _p[x] = find(_p[x]);
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = find(i), y = find(j);
            _numSets--;
            if (_rank[x] >= _rank[y]) {
                // 把集合y添加到集合x
                _p[y] = x;
                _setSize[x] += _setSize[y];
                _numSets--;
                if (_rank[x] == _rank[y])
                    _rank[x]++;
            } else {
                _p[x] = y;
                _setSize[y] += _setSize[x];
            }
        }
    }

    int numSets() const {
        return _numSets;
    }

    int sizeofSet(int x) {
        return _setSize[find(x)];
    }
};