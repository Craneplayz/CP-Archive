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

ifstream fin ("test.in");
ofstream fout ("test.out");

vecl P,ans;

void find_path(int x){
   ans.pb(x);
   if(P[x]==x) return;
   return find_path(P[x]);
}

void solve(){
   int n,k;
   while(cin>>n>>k){
      vector<pair<vecl,ll>> Boxes;
      for(int i=0;i<n;i++){
         vecl Temp;
         for(int j=0;j<k;j++){
            int t;
            cin>>t;
            Temp.pb(t);
         }
         sort(rall(Temp));
         Boxes.pb({Temp,i+1});
      }
      sort(all(Boxes));
      vecl2 Rec(n,vecl());
      ans=vecl();
      for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            bool bi=1;
            for(int h=0;h<k;h++){
               if( Boxes[i].first[h] >= Boxes[j].first[h] ){
                  bi=0;
                  break;
               }
            }
            if(bi) Rec[i].pb(j);
         }
      }

      P.assign(n,-1);
      for(int i=0;i<n;i++) P[i]=i;
      vecl dp(n,1);
      for(int i=0;i<n;i++){
         for(int j=0;j<(int)Rec[i].sz();j++){
            int x=Rec[i][j];
            if(dp[i]+1>dp[x]){
               P[x]=i;
               dp[x]=dp[i]+1;
            }
         }
      }
      ll pos=max_element(all(dp))-dp.begin();
      find_path(pos);
      reverse(all(ans));
      cout<<ans.sz()<<"\n";
      for(ll& i:ans) cout<<Boxes[i].second<<" ";
      cout<<"\n";

      ans.clear();
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