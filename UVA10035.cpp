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
    str a,b;
    while(cin>>a>>b){
        if(a=="0"&&b=="0") break;
        int n=max(a.len(),b.len());
        str ta=str(n-a.len(),'0')+a,tb=str(n-b.len(),'0')+b;
        veci A(n,0),B(n,0);
        for(int i=0;i<n;i++){
             A[i]=ta[i]-'0';
             B[i]=tb[i]-'0';
        }
        veci C(n,0);
        int k=0;
        for(int i=n-1;i>-1;i--){
            C[i]+=A[i]+B[i];
            if(C[i]>=10){
                k++;
                C[i]%=10;
                if(i) C[i-1]++;
            }
        }
        if(k==0) cout<<"No carry operation.\n";
        elif(k==1) cout<<"1 carry operation.\n";
        else cout<<k<<" carry operations.\n";
    }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}