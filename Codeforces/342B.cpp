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
   int n,m,s,f;
   cin>>n>>m>>s>>f;
   char direction;
   if(f>s) direction = 'R';
   else direction = 'L';
   str ans="";
   int T=0;
   for(int i=0;i<m;i++){
      int ti,x,y;
      cin>>ti>>x>>y;
      if(ti>T){
         int N=min(ti-T-1,abs(s-f));
         ans+=str(N, direction );
         T=ti-1;
         if(direction == 'R') s+=N;
         else s-=N; 
      }
      if(s==f) break;
      if(x<=s && s<=y) ans+='X';
      elif(direction == 'R' && x<=s+1 && s+1<=y) ans+='X';
      elif(direction == 'L' && x<=s-1 && s-1<=y) ans+='X';
      else{
         ans+=direction;
         if(direction == 'R') s++;
         else s--; 
      }
      T++;
      //if(s==f) break;
   }

   if(direction == 'R') ans+=str( max(0,f-s) , direction);
   else ans+=str( max(0,s-f) , direction);

   cout<<ans<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}