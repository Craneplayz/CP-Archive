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

ofstream fout ("test.out");
ifstream fin ("test.in");

vecl dR={0,0,1,-1};
vecl dC={1,-1,0,0};


void solve(){
   int n,m;
   cin>>n>>m;
   int mx=(n+1)/2,my=(m+1)/2;
   int Ori=n-mx+m-my;
   mx--; my--; //index 0-based

   vecl2 Graph(n,vecl(m,-1));
   queue<pii> Q;
   Graph[mx][my]=0;
   Q.push({mx,my});
   
   if( !(n&1) && !(m&1) && (mx+1<n) && (my+1<m) ){
      Graph[mx+1][my+1]=0;
      Q.push({mx+1,my+1});
   }

   if( !(n&1) && (mx+1<n) ){
      Graph[mx+1][my]=0;
      Q.push({mx+1,my});
   }

   if( !(m&1) && (my+1<m) ){
      Graph[mx][my+1]=0;
      Q.push({mx,my+1});
   }

   while(!Q.empty()){
      pii f=Q.front(); 
      Q.pop();
      int fx=f.first,fy=f.second;
      cout<<Ori+Graph[fx][fy]<<" ";
      for(int i=0;i<4;i++){
         int nx=fx+dR[i], ny=fy+dC[i];
         if(nx>=n||nx<=-1) continue;
         if(ny>=m||ny<=-1) continue;

         if(Graph[nx][ny]==-1){
            Graph[nx][ny]=Graph[fx][fy]+1;
            Q.push({nx,ny});
         }
      }
   }
   cout<<"\n";
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