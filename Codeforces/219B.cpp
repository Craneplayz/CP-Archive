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
   ll a,d;
   cin>>a>>d;
   int n=log10(a)+1;
   ll c=a;
   ll ans=a,ansc=0;
   str A=to_string(a);
   for(int j=A.len()-1;j>=0;j--){
      if(A[j]=='9') ansc++;
      else break;
   }

   for(int i=1;i<=n;i++){
      ll temp;
      c/=10;
      if(c==0) break;
      str c1=to_string(c-1);
      c1+=str(i,'9');
      temp=stoll(c1);
      ll K=0;
      for(int j=c1.len()-1;j>=0;j--){
         if(c1[j]=='9') K++;
         else break;
      }
      if(a-temp<=d && K>=ansc){
         if(K==ansc) ans=max(ans,temp);
         else ans=temp;
         ansc=K;
      }
   }
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