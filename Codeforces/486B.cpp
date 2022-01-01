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
   int m,n;
   cin>>m>>n;
   veci2 A(m,veci());
   for(int i=0;i<m;i++)
       for(int j=0;j<n;j++){
           int t;
           cin>>t;
           A[i].pb(t);
       }
    
    veci2 B(m,veci(n,1));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(!A[i][j]){
                fill(B[i].begin(),B[i].end(),0);
                for(int h=0;h<m;h++) B[h][j]=0;
            }
    
    veci2 C(m,veci(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            C[i][j]=accumulate(all(B[i]),0,bit_or<int>());
            for(int h=0;h<m;h++) C[i][j]|=B[h][j]; 
        }
            
    if(A!=C) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(auto& i:B){
            for(auto& j:i) cout<<j<<" ";
            cout<<"\n";
        }
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