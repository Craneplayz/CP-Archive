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

ofstream fout ("test.out");
ifstream fin ("test.in");

bool operator< (vecl a,vecl b){
    return *max_element(a.begin(),a.end())<*max_element(b.begin(),b.end());
}

void solve(){
    ll n;
    cin>>n;
    vecl2 a;
    for(ll i=0;i<n;i++){
        ll m;
        cin>>m;
        vecl t1;
        for(int j=0;j<m;j++){
            ll t2;
            cin>>t2;
            t1.pb(t2-j);
        }
        sort(t1.rbegin(),t1.rend());
        a.pb(t1);
    }
    sort(a.begin(),a.end());
    ll L=0,R=3e9,ans=INT_MAX;
    while(L<=R){
        ll mid=(L+R)/2;
        bool check=true;
        ll k=mid;
        for(int i=0;i<n;i++){
            if(k<=a[i][0]){check=0; break;}
            k+=a[i].sz();
            if(!check) break;
        }
        if(check){
            ans=mid;
            R=mid-1;
        }
        else L=mid+1;
    }
    cout<<ans<<'\n';
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