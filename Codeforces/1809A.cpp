#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void solve(){
    string a;
    cin >> a;
    map<char, int> m;
    vector<int> vec(4, 0);
    int I = 0;
    for (int i = 0; i < 4; i++){
        int x = a[i];
        if (m.find(x) == m.end())
            m[x] = I++;
        vec[m[x]]++;
    }
    sort(vec.rbegin(), vec.rend());

    if (m.size() >= 3)
        cout << 4 << '\n';
    else if (m.size() == 2){
        if (vec[0] == 2) cout << "4\n";
        else cout << "6\n";
    }
    else cout << "-1\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}