#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

//Declarations
#define lg long
#define ll long long
#define veci vector<int>
#define str string

//Functions
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ll A,B;
    cin>>A>>B;
    if(B==1) cout<<"NO"<<endl;
    else{
    cout<<"YES"<<endl;
    ll x,y,z;
    x=A*B; //good number
    y=A;
    z=(B+1)*A;
    cout<<x<<" "<<y<<" "<<z<<endl;
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