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
    str a;
    map<str,int> hash;
    int i_hash=0,total=0;
    int cnt[10001];
    memset(cnt,0,sizeof(cnt));
    while(getline(cin,a)){
        if(a=="") break;
        if(hash.find(a)==hash.end()) hash[a]=i_hash++;
        cnt[hash[a]]++;        
        total++;
    }
    cout<<fixed<<setprecision(4);
    for(psi i:hash)
        cout<<i.first<<" "<<((double)cnt[i.second]/total)*100<<"\n";
    
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t; str a;
   cin>>t;
   cin.ignore();
   getline(cin,a);
   while(t--) {
       solve();
       if(t) cout<<'\n';
   }
   
   return 0;
}