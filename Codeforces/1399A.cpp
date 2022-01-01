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
    int n,c,temp;
    bool b=true;
    cin>>n;
    veci a;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]>1) {
            b=false;
            break;
        }
    
    if(b) cout<<"YES\n";
    else cout<<"NO\n";
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