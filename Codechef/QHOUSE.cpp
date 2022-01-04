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

void solve(){
   str res;
   ll L,R,mid;
   //正方形半边
   //y=0;
   L=1;  R=1000;
   ll L1;
   while(L<=R){
      mid=(L+R)/2;
      cout<<"? "<<mid<<" "<<0<<endl;
      cin>>res;
      if(res=="YES"){
         L1=mid;
         L=mid+1;
      }
      else R=mid-1;
   }
   //正方形边长
   ll L2=2*L1;

   //三角形㡳
   //y=L2;
   L=1; R=1000;
   ll L3;
   while(L<=R){
      mid=(L+R)/2;
      cout<<"? "<<mid<<" "<<L2<<endl;
      cin>>res;
      if(res=="YES"){
         L3=mid;
         L=mid+1;
      }
      else R=mid-1;
   }

   //三角形高
   //x=0;
   L=1; R=1000;
   ll L4;
   while(L<=R){
      mid=(L+R)/2;
      cout<<"? "<<0<<" "<<mid<<endl;
      cin>>res;
      if(res=="YES"){
         L4=mid;
         L=mid+1;
      }
      else R=mid-1;
   }

   ll A=L2*L2+L3*(L4-L2);
   cout<<"! "<<A<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}