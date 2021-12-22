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
typedef vector<pair<long long,long long>> vecpll;
typedef vector<pair<string,int>> vecpsi;
typedef vector<bool> vecb;
typedef vector<vector<bool>> vecb2;
typedef string str;

//Functions
#define elif else if
#define lng length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

vecl parent;
vector<vecpll> adj; 
vecl dist;
 
void dijk(ll source){
  dist[source]=0; parent[source]=source;
  priority_queue< pl, vector<pl>, greater<pl> > pq;
  pq.push({0, source}); //comp : distant - vertice
 
  while (!pq.empty()) { // main loop
    pl front=pq.top();
    pq.pop(); // greedy: get shortest unvisited vertex
    ll d=front.first, u=front.second; //distance-vertices
    if (d>dist[u]) continue; //important check
    for(ll j=0;j<adj[u].size();j++){
      pl v=adj[u][j]; // all outgoing edges from u
      if (dist[u]+v.second<dist[v.first]){
        dist[v.first]=dist[u]+v.second; //relaxation
        pq.push({dist[v.first], v.first});
        parent[v.first]=u;
       } 
    } 
  }
}
 
void find_path(ll x){
   if (x!= parent[x])
       find_path(parent[x]);
   cout<<x+1<<' ';
}

void solve(){
  ll n,m;
  cin>>n>>m;
  adj=vector<vecpll>(n,vecpll());
  dist=vecl(n,LLONG_MAX);
  parent=vecl(n,-1);
  for(ll i=0;i<m;i++){
      ll v1,v2,w;
      cin>>v1>>v2>>w;
      adj[v1-1].pb({v2-1,w});
      adj[v2-1].pb({v1-1,w});
  }  
 dijk(0);
 if(dist[n-1]==LLONG_MAX) cout<<"-1\n";
 else {find_path(n-1);
 cout<<"\n";}
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}