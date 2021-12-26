#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

//Declarations
#define lg long
#define ll long long
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecb vector<bool>
#define str string

//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    int n;
    cin>>n;
    str a;
    cin>>a;
    bool b=false;
    for(int i=0;i<a.length();i++) a[i]=tolower(a[i]);
    veci c;
    for(int i=0;i<26;i++) c.pb(0);
    for(char d:a){
        c[d-'a'] ++;
    }
    for(int i:c)
        if(!i) {
            b=true;
            break;
        }
    if(b) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}
