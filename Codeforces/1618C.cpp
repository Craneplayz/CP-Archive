#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
typedef list<int> lsi;
typedef map<int,int> mii; 
typedef map<int,char> mic; 
typedef map<char,int> mci;
typedef map<string,int> msi; 
typedef map<string,pair<int,int>> mspii; 
typedef map<string,map<int,int>> msmii;
typedef pair<int,int> pii;
typedef pair<long long,long long> pl;
typedef pair<string,int> psi;
typedef queue<int> qi;
typedef vector<int> veci;
typedef vector<int>::iterator itveci; 
typedef vector<vector<int>> veci2;
typedef vector<long long> vecl;
typedef vector<vector<long long>> vecl2;
typedef vector<float> vecf;
typedef vector<vector<float>> vecf2;
typedef vector<string> vecs;
typedef vector<vector<string>> vecs2;
typedef vector<pair<int,int>> vecpii;
typedef vector<pair<long long,long long>> vecpl;
typedef vector<pair<string,int>> vecpsi;
typedef vector<bool> vecb;
typedef vector<vector<bool>> vecb2;
typedef string str;

//Functions
#define elif else if
#define len length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Ver.
// #define __gcd gcd //c++20

//Debug
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    ll n;
    cin>>n;
    vecl odd,even;
    for(ll i=0;i<n;i++){
        ll t;
        cin>>t;
        if(i&1) odd.pb(t);
        else even.pb(t);
    }
    ll GA=odd[0],GB=even[0];
    for(ll i=1;i<(ll)odd.sz();i++) GA=__gcd(GA,odd[i]);
    for(ll i=1;i<(ll)even.sz();i++) GB=__gcd(GB,even[i]);
    bool bA=1,bB=1;
    for(ll i=0;i<(ll)odd.sz();i++)
        if(!(odd[i]%GB)){bA=0; break;}

    for(ll i=0;i<(ll)even.sz();i++)
        if(!(even[i]%GA)){bB=0; break;}
    
    if(bA&&bB) cout<<max(GA,GB)<<'\n';
    elif(bA) cout<<GB<<'\n';
    elif(bB) cout<<GA<<'\n';
    else cout<<0<<'\n';
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