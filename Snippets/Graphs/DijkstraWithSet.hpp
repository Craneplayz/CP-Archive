#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<pair<int, int>>> adj; // Adjacency List, adj[u]: {w,v}
vector<int> d; // Distance

/// @brief Dijkstra's Algorithm Implementation with Set
/// @param s Source point
void dijkstra(int s){
    d[s] = 0;
    set<pair<int, int>> S;
    S.insert({0, s});
    while (!S.empty()){
        pair<int, int> front = *S.begin();
        S.erase(S.begin());
        int du = front.first, u = front.second;
        if (du > d[u])
            continue;
        for (int i = 0; i < (int)adj[u].size(); i++){
            pair<int, int> v = adj[u][i];
            if (d[u] + v.first < d[v.second]){
                d[v.second] = d[u] + v.first;
                S.insert(v);
            }
        }
    }
}

int main(){
    // Prepare adj

    int s; // Declare starting point 
    d.assign((int)adj.size(), INT_MAX);
    dijkstra(s);

    return 0;
}