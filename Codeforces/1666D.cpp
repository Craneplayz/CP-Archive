//Editorial
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
#ifndef ONLINE_JUDGE
#define cin fin
#define cout fout
#endif

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   str a,b;
   cin>>a>>b;
   veci A(26,0), B(26,0), C(26,0);
   for(int i=0;i<(int)a.len();i++)  A[a[i]-'A']++;
   for(int i=0;i<(int)b.len();i++)  B[b[i]-'A']++;
   for(int i=0;i<26;i++)  C[i]=A[i]-B[i];
   for(int i=0;i<26;i++){
      if(C[i]<0){
         cout<<"NO\n";
         return;
      }
   }
   for(int i=0;i<(int)a.len();i++){
      if(C[a[i]-'A']){
         C[a[i]-'A']--;
         a.erase(a.begin()+i);
         i--;
      }
   }
   if(a==b) cout<<"YES\n";
   else cout<<"NO\n";
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