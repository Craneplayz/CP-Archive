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

typedef long long ll;
typedef long double ld;
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e9

// Array = Vector
vector<vector<int>> adj; // Adjacency List
vector<bool> visited;

/// @brief Depth First Search
/// @param s Source
void dfs(int s) {
    stack<int> st;     // 开设一个Stack，FILO
    st.push(s);        // 把Source放进Stack
    visited[s] = true; // Source已经走过了

    while (!st.empty()) {
        int u = st.top(); // Stack 第一个元素 = 最后放入的元素
        st.pop();         // 丢掉这个元素
        cout << u << "\n";
        for (int v : adj[u]) { // u -> v，对于现在这个u，u能达到的每个邻居v
            if (!visited[v]) { // If `visited[v] == false`
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

// CamelCase
// Clever Fox -> cleverFox
void dfsRecurse(int u) {
    visited[u] = true;
    cout << "Preorder" << u << "\n";
    for (int v : adj[u]) {
        if(!visited[v]){
            visited[v] = true;
            dfsRecurse(v);
        }
    }
    cout << "Post-order" << u << "\n";
}

/// @brief Breadth First Search
/// @param s Source
void bfs(int s) {
    queue<int> q;      // 开设一个Queue，FIFO
    q.push(s);         // 把Source放进Queue
    visited[s] = true; // Queue已经走过了

    while (!q.empty()) {
        int u = q.front(); // Queue 第一个元素 = 最先放入的元素
        q.pop();           // 丢掉这个元素
        cout << u << "\n";
        for (int v : adj[u]) { // u -> v，对于现在这个u，u能达到的每个邻居v
            if (!visited[v]) { // If `visited[v] == false`
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

#define INF 1e9 // 10^9
vector<int> dist(n, INF);
vector<vector<int>> adj(n, vector<int>());

void generateDistance(int s) {
    queue<int> q;
    q.push(s)
        dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[q])
            if (dist[u] + 1 < dist[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
}

// n! = n * (n-1) * (n-2) * ... * 2 * 1

int fact(int n) {
    if (n == 1)
        return 1;

    int ans = n * fact(n - 1);
    cout << n << " " << ans << "\n";
    return ans;
}

int main() {
    int n = 10;
    adj.assign(n, vector<int>()); // Graph
    visited.assign(n, 0);         // 一开始都没有节点是被走过的

    cout << fact(7) << "\n";
    return 0;
}