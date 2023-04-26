#include <bits/stdc++.h> 
using namespace std;

// Macro 的用法
#define str string
#define elif else if

void solve(){
    str t;
    cin >> t; 
    char open = t.front(), close = t.back();
    
    if (close != open) {
        int c1 = 0, c2 = 0;
        vector<str> m1(t.size()), m2(t.size());
        for (int i = 0; i < t.size(); i++){
            if (t[i] == open){ 
                m1.push_back("("); 
                m2.push_back("(");
            }
            elif (t[i] == close){ 
                m1.push_back(")"); 
                m2.push_back(")");
            }
            else{ 
                m1.push_back("("); 
                m2.push_back(")"); 
            }

            // 这里建议不要用 i，会和上一层的For-Loop Clash到
            for (auto i : m1){
                if (i == "(") c1++;
                elif (i == ")" && c1 > 0) c1--;
                elif (i == ")" && c1 <=0 ) {
                    c1 = -1; 
                    break;
                }
            }

            for (auto i : m2){
                if (i == "(") c2++;
                elif (i == ")" && c2 > 0) c2--;
                elif (i == ")" && c2 <=0 ) {
                    c2 = -1; 
                    break;
                }
            }
        }

        if (c1 == 0 || c2 == 0) 
            cout << "YES\n";
    }
   
   cout << "NO\n";

}

int main() {
    // Fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
        solve();

    return 0;
}
        