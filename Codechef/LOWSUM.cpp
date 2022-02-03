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
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   int n,Q;
   cin>>n>>Q;
   vecl A(n),B(n);
   for(int i=0;i<n;i++) cin>>A[i];
   for(int i=0;i<n;i++) cin>>B[i];

   sort(all(A));  sort(all(B));
   vecl K;
   
   /*Key observation:
      if picking A[i] and pairing with B[0-k]
      A[i-1] will pair with B[0-k] too
      for each A[i] pick j=[0,Limit/imax] B[j]
   */
   for(int i=0;i<min(n,10000);i++){
      int k=min(n,(int)ceil(10000./(i+1)));
      for(int j=0;j<k;j++) K.pb(A[i]+B[j]);
   }

   sort(all(K));
   while(Q--){
      int q;
      cin>>q;
      cout<<K[q-1]<<'\n';
   }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   // cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;

   return 0;
}