//Editorial-ed
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

veci2 Graph;
vecb d;

void dfs(int s){
   if(d[s]) return; 
   d[s]=1;

   for(int i=0;i<(int)Graph[s].sz();i++){
      if(!d[ Graph[s][i] ]) dfs( Graph[s][i] );
   }

}

bool check(int a,int b){
   d.assign(Graph.sz(),0);
   dfs(a);
   return d[b];
}

void solve(){
   int n;
   cin>>n;
   int id=0;
   veci L,R;
   for(int i=0;i<n;i++){
      int op,x,y;
      cin>>op>>x>>y;
      if(op==1){
         L.pb(x);
         R.pb(y);
         Graph.pb(veci());
         for(int i=0;i<(int)Graph.sz();i++){
            //Important: One-way
            int b = (x<L[i]&&L[i]<y) || (x<R[i]&&R[i]<y);
            int c = (L[i]<x && x<R[i]) || (L[i]<y && y<R[i]);
            if(b) Graph[i].pb(id);
            if(c) Graph[id].pb(i);
         }
         id++;
      }
      else{
         x--; y--;
         if(check(x,y)) cout<<"YES\n";
         else cout<<"NO\n";
      }
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