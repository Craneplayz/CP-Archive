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

ll n,m;
vecl d,a;

bool check(ll days){
    vecpl s;
    vecb b(n,0);
    for(int i=0;i<m;i++) s.pb({-1,i}); 

    for(ll i=0;i<days;i++) 
        if(d[i]) s[d[i]-1].first=i;

    for(ll i=0;i<m;i++)
        if(s[i].first==-1) return 0;
        else b[s[i].first]=1;

    sort(s.begin(),s.end());

    ll k=s[0].first;
    for(ll i=0;i<m;i++){
        if(i) k+=s[i].first-(s[i-1].first+1);
        k-=a[s[i].second];
        if(k<0) return 0;
    }

    return 1;
}

void solve(){
   cin>>n>>m;
   for(ll i=0;i<n;i++){
       ll t;
       cin>>t;
       d.pb(t);
   }
   for(ll i=0;i<m;i++){
       ll t;
       cin>>t;
       a.pb(t);
   }

   ll L=1,R=n,ans=-1;
   while(L<=R){
       ll mid=(L+R)/2;
       if(check(mid)){
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