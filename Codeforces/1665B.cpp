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
#ifndef ONLINE_JUDGE
#define cin fin
#define cout fout
#endif

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   int n;
   cin>>n;
   map<int,int> M;
   veci A;
   int g=0;
   for(int i=0;i<n;i++){
      int t;
      cin>>t;
      if(M.find(t)==M.end()) {
         M[t]=g++;
         A.pb(1);
      }
      else A[M[t]]++;
   }
   int m=*max_element(all(A));
   int k=m;
   int ans=0;
   while(k!=n){
      //Clone
      ans++;
      //Swap
      ans+=min(m,n-k);
      k+=min(m,n-k);
      m*=2;
   }
   cout<<ans<<"\n";
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