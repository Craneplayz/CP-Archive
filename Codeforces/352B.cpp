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

void solve(){
   int n;
   cin>>n;
   vecl2 P(100000,vecl());
   vecl B(100000,-1);
   for(int i=0;i<n;i++){
      int t;
      cin>>t;
      t--;
      if(B[t]==-1) B[t]=1;
      P[t].pb(i);
      int l=P[t].sz();
      if(l>2 && P[t][l-1]-P[t][l-2]!=P[t][l-2]-P[t][l-3]) B[t]=0;
   }

   cout<<count(all(B),1)<<'\n';
   for(int i=0;i<100000;i++){
      if(B[i]==1){
         cout<<i+1<<" ";
         int l=P[i].sz();
         switch (l)
         {
         case 1:
            cout<<0<<"\n";
            break;
         default:
            cout<<P[i][l-1]-P[i][l-2]<<"\n";
            break;
         }
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