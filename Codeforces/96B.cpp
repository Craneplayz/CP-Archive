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

// //Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

vecl Data;
str rec;

void back(ll c4,ll c7,ll i,ll n){
    if(i==n){
        Data.pb(stoll(rec));
        return;
    }
    if(c4){
        rec[i]='4';
        back(c4-1,c7,i+1,n);
    }
    if(c7){
        rec[i]='7';
        back(c4,c7-1,i+1,n);
    }
}

void solve(){
    ll n;
    cin>>n;
    ll T=1+ceil(log10(n));
    for(ll i=1;i<=(T/2)+1;i++){
        rec=str(2*i,'@');
        back(i,i,0,2*i);
    }
    //sort(Data.begin(),Data.end());
    ll L=0,R=Data.sz(),ans=R;
    while(L<=R){
        ll mid=(L+R)/2;
        if(Data[mid]>=n){
            ans=Data[mid];
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
   solve();
    
   return 0;
}