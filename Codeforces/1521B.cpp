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
    int n;
    cin>>n;
    veci a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    auto p=min_element(all(a));
    int I=p-a.begin();
    int x=*p;
    veci b;
    for(int i=I;i<n-1;i++){
        if(__gcd(a[i+1],a[i])!=1){
            b.pb(i+2);
            a[i+1]=a[i]+1;
        }
    }

    for(int i=I;i>0;i--){
        if(__gcd(a[i-1],a[i])!=1){
            b.pb(i);
            a[i-1]=a[i]+1;
        }
    }

    cout<<b.sz()<<"\n";
    for(int& j:b)
        cout<<I+1<<" "<<j<<" "<<x<<" "<<a[j-1]<<"\n";
    
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