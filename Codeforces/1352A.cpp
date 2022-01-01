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
    int n,c=0;
    cin>>n;
    veci a;

    while(1){
        a.pb(n%10);
        n/=10;
        if(!n) break;
    }

    for(int i=0;i<a.size();i++)
        if(a[i]){
            c++;
            a[i]=a[i]*pow(10,i);
        }

    cout<<c<<"\n";
    for(int i:a)
        if(i) cout<<i<<" ";
    
    cout<<"\n";
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