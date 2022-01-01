#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Declarations
#define ll long long
#define veci vector<int>

//Functions
#define pb push_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ll n,c=0,k=1;
    veci vec;
    cin>>n;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        vec.pb(temp-i-1);
    }
    
    sort(vec.begin(),vec.end());
    
    for(ll i=1;i<n;i++){
        if(vec[i-1]==vec[i]) k++;  
        if(vec[i]!=vec[i-1]||i==n-1){
            c+=k*(k-1)/2;
            k=1;
        }
    }

    cout<<c<<"\n";
}

int main(){
   int t;
   cin>>t;
   while(t--) solve();
   return 0;
}