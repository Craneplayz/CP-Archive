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

vector<vector<double>> table;

void backtrack(int n, double p){

}

void solve(){
    int n;
    while (cin >> n) {
        table.assign(n + 1, vector<double>(n + 1, 1));

        for (int i = 0; i < n;i++)
            for (int j = 0; j < n; j++)
                if (i != j) // Ignoring Diagonal
                    cin >> table[i+1][j+1];

        
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