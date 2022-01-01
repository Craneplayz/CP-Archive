//Bipartite

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
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

int n,m;
vecl2 Adj;
vecl d;

void bfs(int i){
   d[i]=0;
   queue<int> Q;
   Q.push(i);
   while(!Q.empty()){
      int a=Q.front();
      Q.pop();
      for(int j=0;j<(int)Adj[a].sz();j++){
         int x=Adj[a][j];
         if(d[a]+1<d[x]){
            d[x]=d[a]+1;
            Q.push(x);
         }
      }
   }
}

void solve(){
   cin>>n>>m;
   Adj.assign(n+1,vecl());
   d.assign(n+1,INT_MAX);
   for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      Adj[x].pb(y);
      Adj[y].pb(x);
   }

   //Generate Distance
   for(int i=1;i<=n;i++){
      if(d[i]==INT_MAX) bfs(i);
   }

   //Check Bipartite
   for(int i=1;i<=n;i++)
      for(int j=0;j<(int)Adj[i].sz();j++){
         if(d[i]%2==d[Adj[i][j]]%2){
            cout<<"IMPOSSIBLE\n";
            return;
         }
      }
   
   //Print Answers
   for(int i=1;i<=n;i++){
      cout<<(d[i]%2)+1;
      if(i<n) cout<<" "; 
   }
   cout<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}