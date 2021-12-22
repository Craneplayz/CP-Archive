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
    int Amp,Fre,k=0;
    cin>>Amp>>Fre;
    while(Fre--){
        if(Amp==1){
            if(Fre) cout<<1<<"\n\n";
            else cout<<1;
            continue;
        }
        if(k++) cout<<"\n\n";
        for(int i=1;i<=Amp;i++){
            for(int j=0;j<i;j++) cout<<i;
            cout<<'\n';
        }
        for(int i=Amp-1;i>0;i--){
            for(int j=0;j<i;j++) cout<<i;
            if(i>1) cout<<'\n';
        }
    }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   for(int i=0;i<t;i++){
       if(i) cout<<"\n\n";
       solve();
       if(i==t-1) cout<<'\n';
   }
   
   return 0;
}