//Editorial-ed
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

veci ans;
veci2 Graph;
map<pii,int> Dict;

void dfs(int x,int k){
   for(int i=0;i<(int)Graph[x].sz();i++){
      int y=Graph[x][i];
      int id = Dict[ pii{x,y} ];
      if(ans[id]==-1){
         ans[id]=k; //edge
         dfs(y,(k+1)%2);
      }
   }
}

void solve(){
   int n;
   cin>>n;
   
   Graph.assign(n,veci());
   
   for(int i=0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      x--; y--;
      Dict[pii{x,y}]=i;
      Dict[pii{y,x}]=i;
      Graph[x].pb(y);
      Graph[y].pb(x);
   }

   //Key Observation: 3 or more edge to 1 node is INVALID
   int q;
   for(int i=0;i<n;i++){
      if(Graph[i].sz()>=3){
         cout<< -1 <<"\n";
         return;
      }
      elif(Graph[i].sz()==1) q=i; 
   }
   
   ans.assign(n-1,-1);
   dfs(q,0);
   for(auto& i:ans){
      if(i==0) cout<<"2 ";
      elif(i==1) cout<<"3 ";
      else cerr<<"something wrong\n";
   }
   cout<<"\n";


   ans.clear();
   Graph.clear();
   Dict.clear();
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