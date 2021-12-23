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

ifstream fin ("test.in");
ofstream fout ("test.out");

vecb2 Map;
int n,m;

void solve(){
   
   cin>>n>>m;
   Map.assign(n,vecb(m,0));
   for(int i=0;i<n;i++)
       for(int j=0;j<m;j++){
           char t;
           cin>>t;
           if(t=='.') Map[i][j]=1;
       }
   ll cnt=0;
   for(int i=0;i<n;i++)
       for(int j=0;j<m;j++){
           if(Map[i][j]){
               cnt++;
               queue<pii> Q;
               Q.push({i,j});
               Map[i][j]=0;
               while(!Q.empty()){
               pii a=Q.front(),b,c,d;
               Q.pop();
               b=c=d=a;
               a.first++; b.first--;
               c.second++; d.second--;
        
               if(a.first<n && Map[a.first][a.second]) {
                   Q.push(a);
                   Map[a.first][a.second]=0;
               }
               if(b.first>-1 && Map[b.first][b.second]) {
                   Q.push(b);
                   Map[b.first][b.second]=0;
               }
               if(c.second<m && Map[c.first][c.second]) {
                   Q.push(c);
                   Map[c.first][c.second]=0;
               }
               if(d.second>-1 && Map[d.first][d.second]) {
                   Q.push(d);
                   Map[d.first][d.second]=0;
               }
            }}
       }
    cout<<cnt<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}