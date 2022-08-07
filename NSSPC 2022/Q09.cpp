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
// #ifndef ONLINE_JUDGE
// #define cin fin
// #define cout fout
// #endif

ifstream fin ("test.in");
ofstream fout ("test.out");

void solve(){
   str a;
   cin>>a;
   if(a.sz()>25) {
      cout<<"Invalid Length\n";
      return;
   }
   set<str> b;
   vecs B;
   str t="";
   for(int i=0;i<(int)a.sz();i++){
      if(islower(a[i])) t+=a[i];
      else{
         if(!t.empty() && b.find(t)==b.end()) {
            b.insert(t);
            B.pb(t);
         }
         t="";
         if(isalpha(a[i])) t+=a[i];
      }
   }
   for(str i:B){
      cout<<i<<' ';
   }
   cout<<"\n"<<b.sz()<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}