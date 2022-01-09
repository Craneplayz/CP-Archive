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
   int n,a,b;
   cin>>n>>a>>b;
   int k=n/2;
   vecl ans(n,0);
   vecb B(n,0);
   ans[0]=a; ans[n-1]=b;
   B[a-1]=1; B[b-1]=1;
   for(int i=1;i<k;i++){
      for(int j=n-1;j>=0;j--){
         if(!B[j]){
            B[j]=1;
            ans[i]=j+1;
            break;
         }
      }
      if(ans[i]==0||ans[i]<a) {cout<<-1<<"\n"; return;}
   }

   for(int i=k;i<n;i++){
      for(int j=0;j<n;j++){
         if(!B[j]){
            B[j]=1;
            ans[i]=j+1;
            break;
         }
      }
      if(ans[i]==0||ans[i]>b) {cout<<-1<<"\n"; return;}
   }

   for(auto& i:ans) cout<<i<<" ";
   cout<<"\n";
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