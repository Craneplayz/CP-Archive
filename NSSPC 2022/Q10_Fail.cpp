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

ifstream fin ("test.in");
ofstream fout ("test.out");

void solve(){
   str a,b="";
   cin>>a;
   for(int i=0;i<50;i++){
      if(a.empty()) break;
      b="";
      b+=a[0];
      char t;
      for(int j=0;j<(int)a.sz();j++){
         if(j&&a[j]==b.back()) {
            t=b.back();
            b.pop_back();
         }
         elif(a[j]!=b.back()||a[j]!=t){
            b+=a[j];
            t=a[j];
         }
      }
      a=b;
   }
   if(a.empty()) cout<<"Empty String\n";
   else cout<<a<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}