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
   ll n,k;
   cin>>n>>k;
   vecl a(n);
   for(ll i=0;i<n;i++) cin>>a[i];

   if(n==1){
       cout<<max(0LL,a[0]-k)<<'\n';
       return;
   }

   sort(all(a));
   ll sum=accumulate(all(a),0LL);
   if(sum<=k){
       cout<<0<<"\n";
       return;
   }

   ll K=0,ans=sum-k;
   double c=1;
   for(ll i=n-1;i>0;i--){
       K+=a[i]-a[0];
       ll d=max(0LL,sum-K-k); //get current 
       ll m=ceil(d/(c+2))+c; 
       //decreased needed: current/(S(a[i])+a[0])
       //c :: op2 executed
       ans=min(m,ans);
       c++;
   }
   cout<<ans<<"\n";
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