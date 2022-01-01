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

void input(dqi* a,dqi* b,int k){
    for(int i:*a)
        if(i!=k) b->pb(i);
}

bool isPalin(dqi* a){
    int i=0,j=a->sz()-1;
    while(i<j){
        if((*a)[i]!=(*a)[j]) return false;
        i++;
        j--;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    dqi a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.pb(t);
    }
    int i=0,j=n-1,k=-1;
    while(i<j){
        if(a[i]==a[j]){
            a.ppf();
            a.ppb();
            j-=2;
        }
        else{
            dqi b,c;
            input(&a,&b,a[i]);
            if(isPalin(&b)) {
                cout<<"YES\n";
                return;
            }
            input(&a,&c,a[j]);
            if(isPalin(&c)){
                cout<<"YES\n";
                return;
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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