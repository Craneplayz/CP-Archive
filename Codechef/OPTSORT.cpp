//Editorial: https://discuss.codechef.com/t/optsort-editorial/97324

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

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++) cin>>a[i];
   vector<int> b=a;
   sort(all(b));

   // A: elements present in a but not b
   // B: elements present in b but not a
   multiset<int> A,B;
   
   int k=0; //index::b of current min
   ll ans=0;
   for(int i=0;i<n;i++){
      //containing: haven't covered
      //removed: covered in both a and b
      //IMPORTANT: Remove one at once
      if(B.find(a[i])!=B.end()) B.erase(B.find(a[i]));
      else A.insert(a[i]);
      
      if(A.find(b[i])!=A.end()) A.erase(A.find(b[i]));
      else B.insert(b[i]);
      // if same: both will be deleted/not-inserted

      if(A.empty()&&B.empty()){
         ans+=b[i]-b[k];
         k=i+1;
      }
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