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
veci d;

void dijk(int s){
   d[s]=0;
   priority_queue<pii,vecpii,greater<pii>> pq;
   pq.push({d[s],s});
   while(!pq.empty()){
      pii front=pq.top();
      pq.pop();
      int w=front.first,u=front.second;
      if(d[u]<w) continue;
      for(int i=0;i<adj[u].size();i++){
         pii v=adj[u][i];
         if(d[u]+v.second<d[v.first]){
            d[v.first]=d[u]+v.second;
            pq.push({d[v.first],v.first});
         }
      }
   }
}

void solve(){
   int f,n;
   cin>>f>>n;
   veci F;
   vecb bF(n+1,0);
   for(int i=0;i<f;i++){
      int t;
      cin>>t;
      F.pb(t);
      bF[t]=1;
   }
   adj=vector<vecpii>(n+1,vecpii());
   if(n==1) {cout<<1; return;}
   cin.ignore();
   str get;
   int l,r,w;
   while(getline(cin,get)){
      if(get=="") break;
      str t1="";
      veci rec;
      for(int i=0;i<get.len();i++){
         if(isdigit(get[i])) t1+=get[i];
               if(i==get.len()-1||get[i]==' '){
                 int t2=stoi(t1);
                 t1="";
                 rec.pb(t2);
         }
      }
      l=rec[0]; r=rec[1]; w=rec[2];
      adj[l].pb({r,w});
      adj[r].pb({l,w});
   }
   veci D(n+1,INT_MAX);
   for(int i=0;i<f;i++){
      d=veci(n+1,INT_MAX);
      dijk(F[i]);
      for(int j=1;j<n+1;j++)
         if(d[j]<D[j]) D[j]=d[j];
   }
   int ans=1,Dsum=*max_element(D.begin()+1,D.end());
   for(int i=1;i<n+1;i++){
      int dsum=0;
      if(!bF[i]){
         d=D;
         dijk(i);
         dsum=*max_element(d.begin()+1,d.end());
         if(dsum<Dsum){
            ans=i;
            Dsum=dsum;
         }
      }
   }
   cout<<ans;
   adj.clear();
   d.clear();
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) {
      solve();
      if(t) cout<<"\n\n";
      else cout<<"\n";
   }
   
   return 0;
}