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
    ll n,root;
    cin>>n;
    vecl b(n),p(n),w(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i]--;
        if(b[i]==i) root=b[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }

    //if 1st not root: break
    if(p[0]!=root) {cout<<"-1\n"; return;}

    //Assign Weight
    ll ma=0;
    vecl D(n,INT_MAX);
    D[root]=0;
    for(int i=1;i<n;i++){
        //x: current node; d: parent
        ll x=p[i],d=D[b[x]];

        //If parent larger than child: break
        if(d==INT_MAX) {cout<<"-1\n"; return;}

        //RW: d is not needed; checking m is sufficient;
        D[x]=max(d+1,ma+1); 
        ma=D[x];
    }

    //Weight=Distance[out]-Distance[in]
    for(int i=0;i<n;i++){
        w[i]=D[i]-D[b[i]];
        cout<<w[i];
        if(i!=n-1) cout<<" "; 
    }
    cout<<"\n";
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