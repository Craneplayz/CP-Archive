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
#define cin fin
#define cout fout

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
veci d,p;

void dijk(int source){
   d[source]=0;
   p[source]=source;
   priority_queue<level> pq;
   pq.push(level{source,0,adj[source][0].e});
   
   while(!pq.empty()){
       level front=pq.top();
       pq.pop();
       int w=front.w,u=front.r,e=front.e;
       if(w>d[u]) continue;
       for(int i=0;i<adj[u].size();i++){
           level v=adj[u][i];
           int after=d[u]+v.w;
           if(e!=v.e) after+=60;
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
       veci T;
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
           for(int i=0;i<rec.size();i++)
               for(int j=i+1;j<rec.size();j++){
                  adj[rec[i]].pb(level{rec[j],(rec[j]-rec[i])*T[I],I});
                  adj[rec[j]].pb(level{rec[i],(rec[j]-rec[i])*T[I],I});
               }
       }
       dijk(0);
       if(d[k]==2000000) cout<<"IMPOSSIBLE\n";
       else cout<<d[k]<<"\n";
   }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   time_t start,end;
   time(&start);

   //Driving Code
   solve();

//    time(&end);
//    double time_taken = double(end - start);
//     cout << "Time taken by program is : " << fixed
//          << setprecision(12)<< time_taken ;
//     cout << " sec " << endl;
    
   return 0;
}