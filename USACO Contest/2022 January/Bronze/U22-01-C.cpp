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

void solve(){
   ll n;
   cin>>n;
   vecl a(n);
   for(ll i=0;i<n;i++) cin>>a[i];

   ll ans=LLONG_MAX;
   ll L=0,R=INT_MAX;
   while(L<=R){
      vecl temp=a;
      ll mid=(L+R)/2;
      int B=0;
      ll c=0;
      for(int i=0;i<n-1;i++){
         if(temp[i]>mid){
            temp[i+1]-=temp[i]-mid;
            c+=2*(temp[i]-mid);
            temp[i]=mid;
         }
         elif(temp[i]<mid){
            B=1; //mid need to be lower
            break;
         }
      }
      if(B==0 && temp[n-1]<mid) B=1;
      elif(B==0 && temp[n-1]>mid) B=2;
      if(!B){
         ans=min(ans,c);
         L=mid+1;
      }
      elif(B==1) R=mid-1;
      else L=mid+1;
   }
   if(ans==LLONG_MAX) cout<<"-1\n";
   else cout<<ans<<'\n';
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