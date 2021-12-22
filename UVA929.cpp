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
#define len length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

vector<vecpii> adj;
veci dist;
veci p;

void dijk(int s){
    dist[s]=0;
    p[s]=s;
    priority_queue<pii, vecpii, greater<pii>> pq;
    pq.push({0,s});
    
    while(!pq.empty()){
        pii front=pq.top();
        pq.pop();
        int d=front.first,u=front.second;
        if(d>dist[u]) continue;
        for(int i=0;i<adj[u].sz();i++){
            pii v=adj[u][i];
            if(dist[v.first]>dist[u]+v.second){
                dist[v.first]=dist[u]+v.second;
                p[v.first]=u;
                pq.push({dist[v.first],v.first});
            }
        }
    }
}

void solve(){
    int N,M;
    cin>>N>>M;
    adj.assign(N*M+1,vecpii());
    dist.assign(N*M+1,2000000);
    p.assign(N*M+1,-1);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            int w,io=i*M+j+1,iu=(i-1)*M+j+1,il=i*M+j,id=(i+1)*M+j+1,ir=i*M+j+2;
            cin>>w;
            if(i==0&&j==0) adj[0].pb({io,w});
            if(i) adj[iu].pb({io,w});
            if(j) adj[il].pb({io,w});
            if(i!=N-1) adj[id].pb({io,w});
            if(j!=M-1) adj[ir].pb({io,w});
        }
    dijk(0);
    cout<<dist[N*M]<<'\n';
    adj.clear();
    dist.clear();
    p.clear();
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