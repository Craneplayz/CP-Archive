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
   veci a(4),b(4);
   for(int i=0;i<4;i++) cin>>a[i];
   for(int i=0;i<4;i++) cin>>b[i];
   sort(all(a)); sort(all(b));

   if(a==b){
      cout<<"no\n";
      return;
   }

   int wa=0,wb=0;
   for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
         if(a[i]>b[j]) wa++;
         if(a[i]<b[j]) wb++;
      }
   }
   // cout<<wa<<" "<<wb<<'\n';

   //a always win
   if(wb>wa) swap(a,b);
  
   // veci c={ a[0]+1, a[1]+1, b[2]-1, b[3]-1};
   // for(int i:c){
   //    if(i<1||i>10){
   //       cout<<"no\n";
   //       return;
   //    }
   // }

   veci c(4);
   for(int I=1;I<=10;I++){
      for(int J=1;J<=10;J++){
         for(int K=1;K<=10;K++){
            for(int L=1;L<=10;L++){
               c={I,J,K,L};
               int ca1=0,ca2=0,cb1=0,cb2=0;
               for(int i=0;i<4;i++){
                  for(int j=0;j<4;j++){
                     if(c[i]>a[j]) ca1++;
                     elif(c[i]<a[j]) ca2++;
                     if(c[i]>b[j]) cb1++;
                     elif(c[i]<b[j]) cb2++;
                  }
               }
               if(ca1>ca2 && cb1<cb2){
                  // for(int i:c) cout<<i<<' ';
                  // cout<<"\n";
                  cout<<"yes\n";
                  return;
               }
            }
         }
      }
   }
   cout<<"no\n";
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