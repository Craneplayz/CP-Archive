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

const ll M = 1e9+7;

void solve(){
   int n;
   cin>>n;
   vecs S;
   vecl2 dp(n,vecl(n,0));
   for(int i=0;i<n;i++){
       str t;
       cin>>t;
       S.pb(t);
   }
   dp[0][0]=(S[0][0]=='*')? 0 : 1;
   for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
           if(S[i][j]=='*') dp[i][j]=0;
           else{
              if(j&&S[i][j-1]!='*') dp[i][j]+=dp[i][j-1];
              if(i&&S[i-1][j]!='*') dp[i][j]+=dp[i-1][j];
              dp[i][j]%=M;
           }
       }
   
   cout<<dp[n-1][n-1]<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}