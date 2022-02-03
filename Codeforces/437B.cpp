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

void solve(){
   int sum,limit;
   cin>>sum>>limit;
   vecl2 LB((int)ceil(log2(limit))+1,vecl());
   for(int i=1;i<=limit;i++){
      int d=log2((i&(-i)));
      LB[d].pb(i);
   }
   int n=LB.sz();
   vecl ans;
   for(int i=n-1;i>=0;i--){
      ll S=LB[i].sz();
      ll P=(1<<i);
      ll M=min(sum/P,S);
      sum-=M*P;
      for(int j=0;j<M;j++)  ans.pb(LB[i][j]);
   }
   if(sum!=0) cout<<-1<<"\n";
   else{
      cout<<ans.sz()<<"\n";
      for(ll& i:ans) cout<<i<<" ";
      cout<<"\n";
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