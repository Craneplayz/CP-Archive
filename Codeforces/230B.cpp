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

//Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

ll Mpow(int a,int b,int m){
    if(b==1) return a%m;
    ll Mod=Mpow(a,b/2,m);
    if(b&1) return (Mod*Mod*a)%m;
    else return (Mod*Mod)%m;
}


bool MillerRabin(int x){
    if(x<3) return x==2;
    if(!(x&1)) return 0;
    int a[]={2,7,61};
    int d=x-1,r=0;
    while(!(d&1)){
        d/=2;
        r++;
    }
    for(int i:a){
        if(i>x-2) break;
        ll v=Mpow(i,d,x);
        if(v==1||v==x-1) continue;
        for(int j=0;j<r;j++){
            v=v*v%x;
            if(v==x-1&&j!=r-1){
                v=1;
                break;
            }
            if(v==1) return false;
        }
        if(v!=1) return false;
    }
    return true;
}

void solve(){
   ll n;
   cin>>n;
   for(ll i=0;i<n;i++){
       ll t;
       cin>>t;
       double b=sqrt(t);
       if(ceil(b)*ceil(b)!=t) cout<<"NO\n";
       elif(MillerRabin(int(b))) cout<<"YES\n";
       else cout<<"NO\n";
   }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}