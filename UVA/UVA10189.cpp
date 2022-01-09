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

vecpl D8={ {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };

void solve(){
   int n,m,TEST=0;
   while(cin>>n>>m){
      if(n==0&&m==0) break;
      if(TEST) cout<<"\n";
      vecs Field;
      for(int i=0;i<n;i++){
         str s="";
         for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='.') c='0';
            s+=c;
         }
         Field.pb(s);
      }

      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(Field[i][j]=='*'){
               for(int h=0;h<8;h++){
                  int x=i+D8[h].first;
                  int y=j+D8[h].second;
                  if(0<=x && x<n && 0<=y && y<m && isdigit(Field[x][y]))
                     Field[x][y]++;
               }
            }
         }
      }

      cout<<"Field #"<<++TEST<<":\n";

      for(str& i:Field) cout<<i<<"\n";
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