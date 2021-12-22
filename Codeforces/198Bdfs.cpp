#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define lsi list<int>
#define mii map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define mspii map<string,pair<int,int>>
#define msmii map<string,map<int,int>>
#define pii pair<int,int>
#define pllll pair<long long,long long>
#define psi pair<string,int>
#define qi queue<int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpllll vector<pair<long long,long long>>
#define vecpsi vector<pair<string,int>>
#define vecb vector<bool>
#define vecb2 vector<vector<bool>>
#define str string


//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

vecs a;
int n,k;
vecb2 b;

bool dfs(int c,int j1,int j2,int m){
    if(j2==-1) return false;
    if(a[j1][j2]=='X') return false;
    if(j2+1>n||j2+k>n) return true;
    if(m>=j2) return false;
    if(b[j1][j2]) return false;
    else b[j1][j2]=true;
    //if(c==1) return dfs(3,(j1+1)%2,j2+k,m+1)||dfs(1,j1,j2+1,m+1);
    //if(c==2) return dfs(2,j1,j2-1,m+1)||dfs(3,(j1+1)%2,j2+k,m+1);
    return dfs(3,(j1+1)%2,j2+k,m+1)||dfs(1,j1,j2+1,m+1)||dfs(2,j1,j2-1,m+1);
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<2;i++){
        str t;
        cin>>t;
        a.pb(t);
        b.pb(vecb(n,0));
    }
    if(dfs(0,0,0,-1)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}