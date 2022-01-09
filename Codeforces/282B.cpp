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
   int n;
   cin>>n;
   veci a(n),g(n);
   for(int i=0;i<n;i++) cin>>a[i]>>g[i];
   str s1="",s2="";
   ll s1A=0,s1G=0,s2A=0,s2G=0;
   for(int i=0;i<n;i++){
      if(!i){
         s1="A";
         s1A+=a[i];
      } 
      else{
         if(abs(s1A-(s1G+g[i]))<=500){
            s1+='G';
            s1G+=g[i];
         }
         else{
            s1+='A';
            s1A+=a[i];
         }
      }
   }


   for(int i=0;i<n;i++){
      if(!i){
         s2="G";
         s2G+=g[i];
      } 
      else{
         if(abs(s2G-(s2A+a[i]))<=500){
            s2+='A';
            s2A+=a[i];
         }
         else{
            s2+='G';
            s2G+=g[i];
         }
      }
   }


   if(abs(s1A-s1G)<=500) cout<<s1<<"\n";
   elif(abs(s2A-s2G)<=500) cout<<s2<<"\n";
   else cout<<"-1\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}