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

map<char,string> Dict={
{'>',"1000"},
{'<',"1001"},
{'+',"1010"},
{'-',"1011"},
{'.',"1100"},
{',',"1101"},
{'[',"1110"},
{']',"1111"}
};

const ll Mod=1e6+3;

ll ModP(ll a,ll b){
   if(b==0) return 1;
   ll M=ModP(a,b/2)%Mod;
   if(b&1) return (M*M*a)%Mod;
   return (M*M)%Mod;
}

void solve(){
   str a;
   cin>>a;
   str s="";
   for(int i=0;i<(int)a.len();i++)
      s+=Dict[a[i]];
   reverse(all(s));
   ll ans=0;
   for(int i=0;i<(int)s.len();i++){
      if(s[i]=='1'){
         ans+=ModP(2,i);
      }
   }
   cout<<ans%Mod<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}