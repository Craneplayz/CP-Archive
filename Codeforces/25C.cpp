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

void solve(){
   ll n,q,sum=0;
   cin>>n;
   vector<vector<int>> Adj(n,veci(n,0));
   for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
           cin>>Adj[i][j];
           if(i>j) sum+=Adj[i][j];
       }

   cin>>q;
   while(q--){
       int x,y,w;
       cin>>x>>y>>w;
       x--; y--;
       if(Adj[x][y]<=w){
           cout<<sum<<" ";
           continue;
       }
       sum-=Adj[x][y]-w;
       Adj[x][y]=w;
       Adj[y][x]=w;
       //Floyd-Warshall's
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                ll K=min(Adj[i][x]+w+Adj[y][j],Adj[i][y]+w+Adj[x][j]);
                if(Adj[i][j]>K){
                    sum-=Adj[i][j]-K;
                    Adj[i][j]=K;
                    Adj[j][i]=K;
                }                
            }
        cout<<sum<<" ";
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