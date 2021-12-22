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
typedef vector<pair<long long,long long>> vecpll;
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
   int n,k=0;
   while(cin>>n){
       if(!n) break;
       if(k++) cout<<"\n";
       veci a;
       for(int i=0;i<n;i++){
           int t;
           cin>>t;
           a.pb(t);
       }
       for(int a1=0;a1<n;a1++)
          for(int a2=a1+1;a2<n;a2++)
            for(int a3=a2+1;a3<n;a3++)
                for(int a4=a3+1;a4<n;a4++)
                    for(int a5=a4+1;a5<n;a5++)
                        for(int a6=a5+1;a6<n;a6++)
                            cout<<a[a1]<<" "<<a[a2]<<" "<<a[a3]<<" "<<a[a4]<<" "<<a[a5]<<" "<<a[a6]<<'\n';

   }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}