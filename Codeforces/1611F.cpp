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

void solve(){
   ll n,s;
   cin>>n>>s;
   vecl a;
   for(ll i=0;i<n;i++){
      ll t;
      cin>>t;
      a.pb(t);
   }
   dqi b;
   ll sum=s;
   ll al=0,l=0,r=0;
   for(ll i=0;i<n;i++){
      b.pb(i);
      sum+=a[i];
      while(sum<0){
         sum-=a[b[0]];
         b.ppf();
         if(b.empty()){break;} 
      }
      if(!b.empty()&&al<b.sz()){
         al=b.sz();
         l=b[0];
         r=b[b.sz()-1];
      }
   }
   if(al==0) cout<<-1<<'\n';
   else cout<<l+1<<" "<<r+1<<'\n';

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