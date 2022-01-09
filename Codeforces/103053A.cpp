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

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

void solve(){
   ll N,Q;
   cin>>N>>Q;
   vecpl P;
   for(int i=0;i<N;i++){
      ll x,y;
      cin>>x>>y;
      P.pb({x,y});
   }

   vecl2 D(N,vecl(N,INT_MAX));
   for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
         ll dx=P[i].first-P[j].first;
         ll dy=P[i].second-P[j].second;
         ll dist=dx*dx+dy*dy;
         D[i][j]=D[j][i]=dist;
      }
   }

   while(Q--){
      ll w,x,y;
      cin>>w>>x>>y;

      if(P[w]==pl{x,y}) {cout<<"equal\n";  continue;}
      P[w]=pl{x,y};
      
      vecl Pw(N,INT_MAX);
      for(int i=0;i<N;i++){
         if(i!=w){
            ll dx=P[i].first-P[w].first;
            ll dy=P[i].second-P[w].second;
            ll dist=dx*dx+dy*dy;
            Pw[i]=dist;
            D[i][w]=dist;
         }
      }

      vecl refer=D[w],sample=Pw;
      sort(all(refer));  sort(all(sample));

      if(sample>refer) cout<<"larger\n";
      elif(sample<refer) cout<<"smaller\n";
      else cout<<"equal\n";

      D[w]=Pw;
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