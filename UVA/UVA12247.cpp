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
    veci a(3,0);
    veci b(2,0);
    while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]){
        if(a==veci(3,0)&&b==veci(2,0)) break;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        veci c(52,0);
        bool bi=0;
        c[a[0]-1]=1; c[a[1]-1]=1; c[a[2]-1]=1; c[b[0]-1]=1; c[b[1]-1]=1;
        if(b[0]>a[2]){
            for(int i=0;i<52;i++) if(!c[i]) {cout<<i+1<<'\n'; bi=1; break;} 
        }
        elif(b[1]>a[2]){
           if(b[0]>a[1]) for(int i=a[1];i<52;i++) {if(!c[i]) {cout<<i+1<<'\n'; bi=1;  break;}} 
           else {for(int i=a[2];i<52;i++) if(!c[i]) {cout<<i+1<<'\n'; bi=1; break;}}
        }
        elif(b[0]>a[1]){
           for(int i=a[1];i<52;i++) if(!c[i]) {cout<<i+1<<'\n'; bi=1; break;}
        }
        if(!bi) cout<<"-1\n";
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