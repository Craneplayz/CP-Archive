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
veci b,parent;
veci2 a;

inline int index(int i,int j){
    return i*m+j;
}

void dfs(int x,int y,int p){
    if(b[index(x,y)]) return;
    parent[index(x,y)]=p;
    b[index(x,y)]=1;

    //left empty
    if(y && !(a[x][y]&(1<<0)) && !b[index(x,y-1)]) dfs(x,y-1,p);

    //down empty
    if(x!=n-1 && !(a[x][y]&(1<<1)) && !b[index(x+1,y)]) dfs(x+1,y,p);

    //right empty
    if(y!=m-1 && !(a[x][y]&(1<<2)) && !b[index(x,y+1)]) dfs(x,y+1,p);

    //up empty
    if(x && !(a[x][y]&(1<<3)) && !b[index(x-1,y)]) dfs(x-1,y,p);
}

void solve(){
   cin>>n>>m;
   b.assign(n*m,0);
   parent.assign(n*m,-1);
   for(int i=0;i<n;i++){
       veci T;
       for(int j=0;j<m;j++){
           int t;
           cin>>t;
           T.pb(t);
       }
       a.pb(T);
   }
   for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
           if(!b[index(i,j)])  dfs(i,j,index(i,j));

   sort(parent.begin(),parent.end());
   parent.pb(-1);
   veci ans;
   int k=1;
   for(int i=1;i<=n*m;i++){
       if(parent[i]!=parent[i-1]){
           ans.pb(k);
           k=0;
       }
       k++;
   }
   sort(ans.rbegin(),ans.rend());
   for(int i:ans) cout<<i<<" ";
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