#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n, -1000);
    int p = 0, b = 500;
    for (int i = 0; k && i < n; i++){
        a[i] = b;
        
        int d = min(k - p, n - i);
        for (int j = 1; j < d; j++)
                a[i + j] = -b + 1;

        if (p + (n - i) < k){
            p += n - i;
            b -= 2;
        }
        else
            break;
    }

    for (int x : a)
        cout << x << " ";

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}