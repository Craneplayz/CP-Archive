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
vecl a,dp;

// void f(ll i,ll w){
//    if(i==n){
//        ans=min(ans,w);
//        return;
//    }
//    if(i+1<=n) return f(i+1,w+1);
//    if(i+2<=n) return f(i+2,w+2);
// }

ll DP(ll i){
   if(dp[i]!=INT_MAX) return dp[i];
   if(i-1>-1) dp[i]=min(dp[i],DP(i-1)+abs(a[i]-a[i-1]));
   if(i-2>-1) dp[i]=min(dp[i],DP(i-2)+abs(a[i]-a[i-2]));
   return dp[i];
}

void solve(){
   cin>>n;
   dp.assign(n,INT_MAX);
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       a.pb(t);
   }
   dp[0]=0;
//    for(int i=0;i<n;i++){
//        if(i+1<n) dp[i+1]=min(dp[i+1],dp[i]+abs(a[i]-a[i+1]));
//        if(i+2<n) dp[i+2]=min(dp[i+2],dp[i]+abs(a[i]-a[i+2]));
//    }
//    cout<<dp[n-1]<<'\n';
//    dp.assign(n,INT_MAX);
//    dp[0]=0;
   //f(-1,0);
   cout<<DP(n-1)<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}