#include <bits/stdc++.h>
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
    str a,b,c;
    cin>>a>>b>>c;
    veci c1,c2;
    bool check=false;

    for(int i=0;i<26;i++){
        c1.pb(0);
        c2.pb(0);
    }

    for(int i=0;i<a.lng;i++) c1[a[i]-'A']++;
    for(int i=0;i<b.lng;i++) c1[b[i]-'A']++;
    for(int i=0;i<c.lng;i++) c2[c[i]-'A']++;

    for(int i=0;i<26;i++)
        if(c1[i]!=c2[i]) {
            check=true;
            break;
        }
    
    if(check) cout<<"NO\n";
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