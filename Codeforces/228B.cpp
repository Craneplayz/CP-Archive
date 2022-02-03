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
   int na,ma;
   cin>>na>>ma;
   veci2 a(na,veci(ma));
   for(int i=0;i<na;i++)
      for(int j=0;j<ma;j++){
         char t;
         cin>>t;
         a[i][j]=t-'0';
      }
   
   int nb,mb;
   cin>>nb>>mb;
   veci2 b(nb,veci(mb));
   for(int i=0;i<nb;i++)
      for(int j=0;j<mb;j++){
         char t;
         cin>>t;
         b[i][j]=t-'0';
      }
         
   int M=-1;
   int ansx,ansy;
   for(int I=-50;I<=100;I++){
      for(int J=-50;J<=100;J++){
         int c=0;
         for(int i=0;i<na;i++){
            for(int j=0;j<ma;j++){
               if(i+I<nb && i+I>-1 && j+J<mb && j+J>-1) c+=a[i][j]*b[i+I][j+J];
            }
         }
         if(c>M){
            M=c;
            ansx=I;
            ansy=J;
         }
      }
   }
   cout<<ansx<<" "<<ansy<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}