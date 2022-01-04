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

int n;
set<veci> a;
veci D, Dict={-1,0,0,10,60,270,1080,4050,14580,51030,174960};

void back(int x){
   if(x==n){
       a.insert(D);
       return;
   }
   for(int i=0;i<3;i++){
       D[x]=i;
       back(x+1);
   }
}

void solve(){
   cin>>n;

//Pre-compute
   D.assign(n,-1);
   back(0);
   ll ans=0;
   for(veci i:a){
       ll cnt=0;
       for(int j=1;j<n-1;j++){
           if(i[j-1]<i[j]&&i[j]>i[j+1]) cnt++;
           if(i[j-1]>i[j]&&i[j]<i[j+1]) cnt++;
       }
       ans+=cnt;
   }
   cout<<ans<<'\n';
   a.clear(); D.clear();

    // cout<<Dict[n]<<"\n";
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