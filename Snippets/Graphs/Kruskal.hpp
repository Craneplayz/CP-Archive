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

#include "UnionFindDisjointSet.hpp"

/// @param n Number of vertices
/// @param edgeList { w, u, v }
long long Kruskal(const int n, vector<tuple<long long, int, int>>& edgeList) {
    const int m = edgeList.size();
    // Sort by weight
    sort(edgeList.begin(), edgeList.end());

    UnionFind dsu(n);
    long long mstCost = 0;
    for (int i = 0; i < m && dsu.numSets() != 1; ++i) {
        auto [w, u, v] = edgeList[i];
        if (!dsu.isSameSet(u, v)) {
            dsu.unionSet(u, v);
            mstCost += w;
        }
    }

    if (dsu.numSets() == 1)
        return mstCost;
    else
        return -1; // Impossible to construct MST
}