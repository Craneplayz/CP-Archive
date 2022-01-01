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

ll n;
vecl2 Adj;
vecl p,ans;

void dfs(ll& i){
    for(ll& j:Adj[i]){
        if(p[i]==j) continue;
        p[j]=i;
        if(ans[j]==1) dfs(j);
        ans[i]+=ans[j];
    }
}

void solve(){
   cin>>n;
   Adj.assign(n,vecl());
   p.assign(n,-1);
   ans.assign(n,1);
   for(ll i=1;i<n;i++){
       ll t;
       cin>>t;
       Adj[t-1].pb(i);
   }
   p[0]=0;
   ll nil=0;
   dfs(nil);
   
   for(ll i=0;i<n;i++){
       cout<<ans[i]-1;
       if(i!=n-1) cout<<" ";
   }
   cout<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}