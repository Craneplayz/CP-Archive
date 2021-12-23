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

int n,m;
str D="";
vecs G;
vecl2 d;
vector<vecpl> P;
pii A,B;

void bfs(){
    P[A.first][A.second]=A;
    d[A.first][A.second]=0;
    queue<pl> Q;
    Q.push(A);
    while(!Q.empty()){
        pl k=Q.front(),X;
        Q.pop();

        for(int i=0;i<4;i++){
            if(i==0) X={k.first+1,k.second};
            elif(i==1) X={k.first-1,k.second};
            elif(i==2) X={k.first,k.second+1};
            elif(i==3) X={k.first,k.second-1};
            if(X.first<0||X.first>=n||X.second<0||X.second>=m) continue;
            if(G[X.first][X.second]!='#'&& d[X.first][X.second]>d[k.first][k.second]+1){
                Q.push(X);
                d[X.first][X.second]=d[k.first][k.second]+1;
                P[X.first][X.second]=k;
            }
        } 
    }
}

void find(pl X){
    int i=X.first, j=X.second;
    pl p=P[i][j]; int px=p.first,py=p.second;
    if(X==p) return;
    if(i==px+1&&j==py) D+='D';
    if(i==px-1&&j==py) D+='U';
    if(i==px&&j==py+1) D+='R';
    if(i==px&&j==py-1) D+='L';
    find(p);
}

void solve(){
   cin>>n>>m;
   G.assign(n,str(m,'@'));
   d.assign(n,vecl(m,INT_MAX));
   P.assign(n,vecpl(m,{-1,-1}));
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cin>>G[i][j];
        if(G[i][j]=='A') A={i,j};
        if(G[i][j]=='B') B={i,j};
    }
   bfs();
   if(d[B.first][B.second]==INT_MAX) cout<<"NO\n";
   else{
       cout<<"YES\n";
       cout<<d[B.first][B.second]<<"\n";
       find(B);
       reverse(all(D));
       cout<<D<<'\n';
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