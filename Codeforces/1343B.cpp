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
    int n;
    cin>>n;
    if((n/2)&1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        int ca=0,cb=0;
        veci a,b;
        for(int i=1;i<=n;i++){
            if(i&1) {
                a.pb(i);
                ca+=i;
            }
            else {
                b.pb(i);
                cb+=i;
            }
        }
        a[(n/2)-1]+=n/2;
        for(int i:b) cout<<i<<" ";
        for(int i:a) cout<<i<<" ";
        cout<<"\n";
    }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}