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

struct Segment{
   ll f1,f2,le,l2,l1;
   Segment(){
      le=0;
   }
};

void solve(){
   ll n;
   cin>>n;
   vecl a;
   vector<Segment> Data;
   Segment s;
   for(ll i=0;i<n;i++){
      ll t;
      cin>>t;
      a.pb(t);
   }
   
   for(ll i=0;i<n;i++){
      if(!i){
         s.f1=a[0];
         if(a[1]>a[0]) s.f2=a[1];
         else s.f2=INT_MAX;
      }
      if(i&&a[i]<=a[i-1]){
         s.l1=a[i-1];
         if(s.le==1) s.l2=-1;
         else s.l2=a[i-2];
         Data.pb(s);
         s=Segment();
         s.f1=a[i];
         if(a[i+1]>a[i]) s.f2=a[i+1];
         else s.f2=INT_MAX;
      }
      s.le++;
      if(i==n-1){
         s.l1=a[i-1];
         if(s.le==1) s.l2=-1;
         else s.l2=a[i-2];
         Data.pb(s);
      }
   }
   ll N=Data.sz(),ans=Data[0].le+1;
   for(ll i=1;i<N;i++){
      ans=max(ans,Data[i].le+1);
      if(Data[i-1].l1<Data[i].f2-1||Data[i-1].l2<Data[i].f1-1){
         ans=max(ans,Data[i].le+Data[i-1].le);
      }
   }
   cout<<min(ans,n)<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}