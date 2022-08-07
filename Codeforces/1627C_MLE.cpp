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
veci2 Graph;
veci B;

bool isBipartite(int x){
   queue<int> Q;
   Q.push(x);
   B[x]=1;
   while(!Q.empty()){
      int f=Q.front();
      Q.pop();
      for(int i=0;i<(int)Graph[f].sz();i++){
         int k=Graph[f][i];
         if(B[k]==-1){
            B[k]=(B[f]+1)%2;
            Q.push(k);
         }
         elif(B[k]==B[f]) return false;
      }
   }
   return true;
}

bool isBipartite_dfs(int x){
   for(int i=0;i<(int)Graph[x].sz();i++){
      int k=Graph[x][i];
         if(B[k]==-1){
            B[k]=(B[x]+1)%2;
            if(!isBipartite_dfs(k)) return false;
         }
         elif(B[k]==B[x]) return false;
   }
   return true;
}

void solve(){
   cin>>n;
  
   veci2 Pre(n,veci());
   for(int i=0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      x--; y--;
      Pre[x].pb(i);
      Pre[y].pb(i);
   }

   Graph.assign(n-1,veci()); //too big - MLE
   for(int i=0;i<n;i++){
      for(int j=0;j<(int)Pre[i].sz();j++)
         for(int k=j+1;k<(int)Pre[i].sz();k++){
            int x=Pre[i][j], y=Pre[i][k];
            Graph[x].pb(y);
            Graph[y].pb(x);
         }
   }
   Pre.clear();
   B.assign(n-1,-1);
   B[0]=1;
   if(!isBipartite_dfs(0)) cout<<"-1\n";
   else{
      for(auto& i:B){
         if(i) cout<<2<<" ";
         else cout<<3<<" ";
      }
      cout<<"\n";
   }
   Graph.clear();
   B.clear();
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