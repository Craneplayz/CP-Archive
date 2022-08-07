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
// #ifndef ONLINE_JUDGE
// #define cin fin
// #define cout fout
// #endif

ifstream fin ("test.in");
ofstream fout ("test.out");

veci d,p,mp;
veci2 a;

void bfs(ll s){
  d[s]=0; p[s]=s;
  queue<int> Q;
  Q.push(s);
 
  while (!Q.empty()) {
    int u=Q.front();
    Q.pop(); 

    for(ll j=0;j<(int)a[u].size();j++){
      int x=a[u][j];
      if (d[x]==-1){
        d[x]=d[u]+1;
        Q.push(x); 
        p[x]=u;
       } 
    } 
  }
}

// void find_path(ll x){
//    if (x!= p[x]){
//        find_path(p[x]);
//        mp[p[x]]++;
//    }
// }

veci desc;

void dfs(ll s){
   if(a[s].sz()==1){
      desc[s]=0;
   }
   
   for(int i=0;i<(int)a[s].sz();i++){
      int x=a[s][i];
      if(desc[x]!=-1) continue;
      else{
         desc[x]=0;
         dfs(x);
      }
      desc[s]+=desc[x]+1;
   }
   
}

void solve(){
   int n;
   cin>>n;
   a.assign(n+1,veci());
   for(int i=0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      a[x].pb(y);
      a[y].pb(x);
   }
   int mi=1;
   for(int i=1;i<=n;i++)
      if(a[i].sz()<a[mi].sz()) mi=i;
   
   d.assign(n+1,-1);
   p.assign(n+1,-1);
   bfs(mi);
   desc.assign(n+1,-1);
   dfs(mi);
   for(int I=1;I<=n;I++){
      cout<<I<<" ";
      int vi=-1;
      int ai=-1;
      for(int i=0;i<(int)a[I].size();i++){
         int x=a[I][i];
         if(d[x]>d[I]){
            if(desc[x]+1>ai){
               vi=x;
               ai=desc[x]+1;
            }
         }
         if(d[x]<d[I]){
            int k= (n-desc[x]) + desc[x]-(desc[I]+1);
            if(k>ai){
               vi=x;
               ai=k;
            }
         }
      }
      cout<<vi<<" "<<ai<<"\n";
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