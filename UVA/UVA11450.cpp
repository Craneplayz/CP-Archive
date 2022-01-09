#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

int M,C;
veci2 Garment;
ll dp[201][21];

int shop(int money,int G){
   if(money<0) return (int)-1e9;
   if(G==-1) return M-money;

   if(dp[money][G]!=-1) return dp[money][G];

   int ans=-1e9;
   for(int i=0;i<(int)Garment[G].sz();i++){
      int price=Garment[G][i];
      ans=max(shop(money-price,G-1),ans);
   }
   return dp[money][G]=ans;
}

void solve(){
   cin>>M>>C;
   for(int i=0;i<C;i++){
      int k;
      cin>>k;
      veci G;
      for(int j=0;j<k;j++){
         int t;
         cin>>t;
         G.pb(t);
      }
      Garment.pb(G);
   }
   memset(dp,-1,sizeof(dp));
   ll ans=shop(M,C-1);
   if(ans>0) cout<<ans<<"\n";
   else cout<<"no solution\n";
   Garment.clear();
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