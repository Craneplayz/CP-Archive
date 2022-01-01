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

//GCD·
ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a % b);
}


bool check(ll a,ll b){
    if(a%2==0 && b%2==0) return 1;
    if(b%3==0) return 1;
    if(gcd(a,b)>1) return 1;
    return 0;
}

void solve(){
    ll n;
    cin>>n;
    do{
        ll i=n,d=0;
        while(true){
        d+=i%10;
        i/=10;
        if(!i) break;
        } 
        if(check(n,d)) {
            cout<<n<<'\n';
            break;
        }
    }while(n++);
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