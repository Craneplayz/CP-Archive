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
   int m,s;
   cin>>m>>s;
   if(m==1&&s==0){
      cout<<0<<" "<<0<<'\n';
      return;
   }
   s--;
   str sa="1"+str(m-1,'0');
   str sb=sa;
   int k1=s,k2=s;
      
   //minimum
   if(k1>=0)
   for(int i=m-1;i>=0;i--){
      int sp=sa[i]-'0';
      int d=9-sp;
      d=min(d,k1);
      k1-=d;
      sa[i]+=d;
   }

   //max
   if(k2>=0)
   for(int i=0;i<m;i++){
      int sp=sb[i]-'0';
      int d=9-sp;
      d=min(d,k2);
      k2-=d;
      sb[i]+=d;
   }

   if(k1!=0||k2!=0) cout<<"-1 -1\n";
   else cout<<sa<<" "<<sb<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}