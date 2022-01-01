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
    int n;
    cin>>n;
    dqi a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.pb(t);
    }
    if(n==1) cout<<a[0]<<'\n';
    else{
    int i=0,j=n-1;
    dqi b;
    while(i<=j){
        b.pf(a[i++]);
        b.pb(a[j--]);
        if(b.sz()>n) b.ppb();
    }
    dqi c1,c2;
    i=0; j=n-1;
    while(i<=j){
        if(i==j){
            c2=c1;
            c1.pf(b[i]);
            c2.pb(b[i]);
            i++;
        }
        else{
            if(b[i]<b[j]) c1.pf(b[i++]);
            else c1.pb(b[j--]); 
        }
    }

    if(c1==a||c2==a){
        for(int k:b) cout<<k<<" ";
        cout<<"\n";
    }
    else cout<<"-1\n";  
    }
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