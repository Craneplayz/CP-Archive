//Greedy Approach

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

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    //m-shops; n-friends
    int m,n;
    vecl2 A;
    vector<vecpl> B;
    cin>>m>>n;
    B.assign(n,vecpl());
    for(int i=0;i<m;i++){
        vecl temp;
        for(int j=0;j<n;j++){
            ll t;
            cin>>t;
            temp.pb(t);
            B[j].pb({t,i});
        }
        A.pb(temp);
    }
    set<ll> a;
    ll m1=INT_MAX;
    for(vecpl& i:B){
        sort(i.rbegin(),i.rend());
        a.insert(i[0].second);
        m1=min(i[0].first,m1);
    }
    if(a.sz()<=n-1) {cout<<m1<<"\n"; return;}
    ll m2=-1;
    for(vecl& i:A) {
        sort(i.rbegin(),i.rend());
        m2=max(i[1],m2);
    }
    cout<<min(m1,m2)<<"\n";
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