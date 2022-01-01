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
#define lng length
#define size sz
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    ll n;
    cin>>n;
    veci2 a;
    for(int i=0;i<n;i++){
        veci t1;
        for(int j=0;j<n;j++){
            char t2;
            cin>>t2;
            t1.pb(t2-'0');
        }
        a.pb(t1);
    }
    bool d=0;
    for(int I=n-1;I>-1;I--){
        for(int i=0;i<=I;i++){
            if(I==n-1){
                if(a[i][I]==1) {a[i][I]=2; d=1;}
                if(a[I][i]==1) {a[I][i]=2; d=1;}
                continue;
            }
            if(a[i][I+1]==2||(i+1<n&&a[i+1][I]==2)){
                if(a[i][I]==1) {a[i][I]=2; d=1;}
            }
            if(a[I+1][i]==2||(i+1<n&&a[I][i+1]==2)){
                if(a[I][i]==1) {a[I][i]=2; d=1;}
            }
                
            if(d==1) {
                I++;
                d=0;
            }
        }    
    }
    bool b=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]==1){
                b=1;
                break;
            }
    if(b) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}