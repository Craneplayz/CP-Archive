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
   ll n,k;
   cin>>n>>k;
   vecl s;
   for(ll i=0;i<n;i++){
       ll t;
       cin>>t;
       s.pb(t);
   }
   ll L=s[n-1], R=(n==1)? s[n-1] : s[n-1]+s[n-2];
   ll ans=L;
   k=min(n,k);
   while(L<=R){
       ll mid=(L+R)/2;
       bool check=1;
       //k=min(n,k);
       //below k<=n;
       //no. of single: 2k-n
       //no. of boxes with pair: n-k
       //no. of bell in pair: n-(2k-n)=2(n-k)
       //if (n-k) pairs = {0,2(n-k)-1} {1,2(n-k)-2}
       //                 ... {n-k-1,2(n-k)-1-(n-k-1)=n-k}
       for(ll i=0;i<(n-k);i++){
           if(s[i]+s[2*(n-k)-1-i]>mid) {check=0; break;} 
       }
       if(check){
           ans=mid;
           R=mid-1;
       }
       else L=mid+1;
   }
   cout<<ans<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}