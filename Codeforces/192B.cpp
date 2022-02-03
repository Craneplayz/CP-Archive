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

int n;
veci Road(1001,0);

bool check(){
   veci B(1001,0);
   B[0]=!Road[0];
   for(int i=0;i<1001;i++){
      if(i+1<1001 && !Road[i+1]) B[i+1] |= B[i];
      if(i+2<1001 && !Road[i+2]) B[i+2] |= B[i];
   }
   return B[n-1]; 
}

void solve(){
   cin>>n;
   veci a;
   veci2 b(1001,veci());
   for(int i=0;i<n;i++) {
      int t;
      cin>>t;
      a.pb(t);
      b[t].pb(i);
   }
   veci A=a;
   sort(all(A));
   ll ans;
   for(int i:A){
      ans=i;
      for(int j:b[i]) Road[j]=1;
      if(!check()) break;
   }
   cout<<ans<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}