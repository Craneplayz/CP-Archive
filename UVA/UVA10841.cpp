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

struct level{
    int r,w,e;
};

bool operator<(const level &a, const level &b){
    return a.w>b.w;
}

int n,k;
vector<vector<level>> adj;
veci d,p,T;
veci2 ri;

void dijk(int source,int E){
   if(k==source) {
       d[k]=0;
       return;
   }
   d[source]=max((source-ri[E][0])*T[E],(ri[E][ri[E].size()-1]-source)*T[E]);
   p[source]=source;
   priority_queue<level> pq;
   pq.push(level{source,0,E});
   
   while(!pq.empty()){
       level front=pq.top();
       pq.pop();
       int w=front.w,u=front.r,e=front.e;
       if(w>d[u]) continue;
       for(int i=0;i<adj[u].size();i++){
           level v=adj[u][i];
           int after=d[u]+v.w;
           if(e!=v.e) after+=max((u-ri[v.e][0])*T[v.e],(ri[v.e][ri[v.e].size()-1]-u)*T[v.e])+5;
           if(after<d[v.r]){
               d[v.r]=after;
               p[v.r]=u;
               pq.push(level{v.r,d[v.r],v.e});
           }
       }
   }
}

void solve(){
   while(cin>>n>>k){
       for(int i=0;i<n;i++){
           int t;
           cin>>t;
           T.pb(t);
       } 
       adj=vector<vector<level>>(100,vector<level>());
       d=veci(100,2000000);
       p=veci(100,-1);
       cin.ignore();
       for(int I=0;I<n;I++){
           str temp,t1="";
           veci rec;
           int t3=-1;
           getline(cin,temp);
           for(int j=0;j<temp.len();j++){
               if(isdigit(temp[j])) t1+=temp[j];
               if(j==temp.len()-1||temp[j]==' '){
                 int t2=stoi(t1);
                 t1="";
                 rec.pb(t2);
               }
           }
           ri.pb(rec);
           for(int i=0;i<rec.size();i++)
               for(int j=i+1;j<rec.size();j++){
                  adj[rec[i]].pb(level{rec[j],(rec[j]-rec[i])*T[I],I});
                  adj[rec[j]].pb(level{rec[i],(rec[j]-rec[i])*T[I],I});
               }
       }
       
       for(int i=0;i<n;i++)
           if(count(ri[i].begin(),ri[i].end(),0)) dijk(0,i);
       
       if(d[k]==2000000) cout<<"IMPOSSIBLE\n";
       else cout<<d[k]<<"\n";
       T.clear();
       ri.clear();
   }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
//    time_t start,end;
//    time(&start);

   //Driving Code
   solve();

//    time(&end);
//    double time_taken = double(end - start);
//     cout << "Time taken by program is : " << fixed
//          << setprecision(12)<< time_taken ;
//     cout << " sec " << endl;
    
   return 0;
}