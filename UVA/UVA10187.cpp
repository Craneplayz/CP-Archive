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

struct path{int R,T,W;};

bool operator<(path a,path b){
    return a.W>b.W;
}

vector<vector<path>> adj;
vecpii d,p;
int Begin;

void dijk(int source){
    priority_queue<path> pq;
    d[source].first=0;
    p[source].first=source;
    if(!adj[source].empty()) pq.push(path{source,adj[source][0].T,d[source].first});
    
    while(!pq.empty()){
        int w=pq.top().W,u=pq.top().R,T=pq.top().T;
        pq.pop();

        if(w>d[u].first) continue;

        for(int i=0;i<adj[u].sz();i++){
            path v=adj[u][i];
            
            int Ti=v.T+v.W,after=d[u].first+v.W;
            if(Ti>24) Ti-=24; 
            if(u==source) d[v.R].second=-1;
            if(v.T<d[u].second) after+=24-(d[u].second-v.T);
            elif(d[u].second!=-1) after+=v.T-d[u].second;

            if(d[v.R].first>after){
                d[v.R].first=after;
                d[v.R].second=Ti;
                if(u==source) p[v.R].second=T;
                p[v.R].first=u;
                pq.push(path{v.R,v.T,d[v.R].first});
            }
        }
    }
}

void find(int x,int y){
    if(p[y].first==x) Begin=p[y].second;
    if(p[y].first==-1) return;
    if(y!=p[y].first) find(x,p[y].first);
}

void solve(){
    int n;
    cin>>n;
    msi hash;
    int k=0;
    for(int i=0;i<n;i++){
        str t1,t2;
        int k1,k2;
        cin>>t1>>t2>>k1>>k2;
        if(hash.find(t1)==hash.end()) {
            hash[t1]=k++;
            adj.pb(vector<path>());
        }
        if(hash.find(t2)==hash.end()) {
            hash[t2]=k++;
            adj.pb(vector<path>());
        }
        if(k1==0) k1=24;
        if((k1>=18||k1<=6)&&(k2<=12)&&((k1+k2)%24<=6||(k1+k2)%24>=18)){
            adj[hash[t1]].pb(path{hash[t2],k1,k2});
        }
    }
    str st,et;
    cin>>st>>et;
    if(hash.find(st)==hash.end()||hash.find(et)==hash.end()){
        cout<<"There is no route Vladimir can take.\n";
    }
    else{
    d=vecpii(hash.size(),{2000000,-1});
    p=vecpii(hash.size(),{-1,-1});
    int source=hash[st],end=hash[et];
    dijk(source);
    if(p[end].first==-1) cout<<"There is no route Vladimir can take.\n";
    else{
        find(source,end);
        if(Begin>6) Begin=36-Begin;
        else Begin=12-Begin;
        cout<<"Vladimir needs "<<(d[end].first-Begin+23)/24<<" litre(s) of blood.\n";
    }}
    adj.clear();
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   for(int i=1;i<t+1;i++) {
       cout<<"Test Case "<<i<<".\n";
       if(i==41){
           int k=0;}
       solve();
   }
   
   return 0;
}