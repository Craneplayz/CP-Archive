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

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries) {
        unordered_map<int, vector<int>> m;
        const int n = s.length();

        for (int i = 0; i < n; i++) { //O(n^2)
            if (s[i] == '0'){
                // Record first occurence of zero
                if (!m.count(0)){ 
                    m[0] = {i, i};
                }
                continue;
            }

            // The maximum possible j is 30
            // due to 10^9 approx. = 2^30
            for (int j = 0, num = 0; j < 30 && i + j < n;j++) {
                // Left shift {num}, append the last bit with OR Operation
                // Deduct character '0' to cast into int
                num = (num << 1) | (s[i + j] - '0');
                
                // If this number doesn't exist in the hash map,
                // insert the substring
                if (!m.count(num)) {
                    m[num] = {i, i + j};
                }
            }
        }

        vector<vector<int>> ans;
        for (const auto &q : queries) {
            
            // XOR的自反性 -- "移项"
            // val ^ first == second
            // val = second ^ first
            
            if (m.count(q[0] ^ q[1]))
                ans.push_back(m[q[0] ^ q[1]]);
            else
                ans.push_back({-1, -1}); 
        }

        return ans;
    }
};