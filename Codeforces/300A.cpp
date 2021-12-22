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

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   int n;
   cin>>n;
   veci a,b,c;
   bool bo=0;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       if(t<0){
           if(bo) c.pb(t);
           else {a.pb(t); bo=1;}
       }
       elif(t>0) b.pb(t);
       else c.pb(t);
   }
   sort(c.begin(),c.end(),greater<int>());

   if(b.empty()){
       b.pb(c[c.sz()-1]);
       b.pb(c[c.sz()-2]);
       c.ppb();
       c.ppb();
   }


   cout<<a.sz()<<" ";
   for(int i:a) cout<<i<<" ";
   cout<<"\n";
   cout<<b.sz()<<" ";
   for(int i:b) cout<<i<<" ";
   cout<<"\n";
   cout<<c.sz()<<" ";
   for(int i:c) cout<<i<<" ";
   cout<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}