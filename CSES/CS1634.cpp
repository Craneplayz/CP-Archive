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

// ll N;
// vecl a2,dp2((int)1e6+1,INT_MAX);

// ll top_down(int x){
//     if(!x) return dp2[0]=1;
//     ll ans=INT_MAX;
//     for(int i=0;i<N;i++){
//         if(x-a2[i]<0) dp2[x]=min(dp2[x],1+dp2[x-a2[i]]);
//     }
// }

void solve(){
   ll n,x,a[101];
   ll dp[(int)1e6+1];
   //vecl dp((int)1e6+1,INT_MAX);
   cin>>n>>x;
   for(int i=0;i<n;i++){
       cin>>a[i];
       dp[a[i]]=1;
   }
   for(int i=1;i<=x;i++){
       for(int j=0;j<n;j++)
           if(i-a[j]>0)
           dp[i]=min(dp[i],dp[i-a[j]]+dp[a[j]]);
   }
   if(dp[x]==INT_MAX) cout<<-1<<'\n';
   else cout<<dp[x]<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}