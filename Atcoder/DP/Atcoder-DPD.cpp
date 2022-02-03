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
#define cin fin
#define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

ll N,W,ans=-1;
vecl w,v;
vecl2 dp;

//Complete Search
// void knapsack(ll i,ll wi){
//     if(i==N+1) return;

//     //skip
//     dp[i][wi]=dp[i-1][wi];
//     ans=max(ans,dp[i][wi]);
//     knapsack(i+1,wi);

//     //take
//     ll wii=wi+w[i];
//     if(wii<=W){
//         dp[i][wii]=dp[i-1][wi]+v[i];
//         ans=max(ans,dp[i][wii]);
//         knapsack(i+1,wii);
//     }
// }

ll knapsack(ll i,ll wi){
    if(wi<0) return -1e9;
    if(!i) return 0;

    if(dp[i][wi]) return dp[i][wi];

    return dp[i][wi]=max( knapsack(i-1,wi), knapsack(i-1,wi-w[i])+v[i] );
}

void solve(){
   cin>>N>>W;
   w.assign(N+1,0); v.assign(N+1,0);
   dp.assign(N+1,vecl(W+2,0));
   for(ll i=1;i<=N;i++) cin>>w[i]>>v[i];
   cout<<knapsack(N,W)<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}