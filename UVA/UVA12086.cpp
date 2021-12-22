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


struct FenwickTree{
    veci ft;
    FenwickTree(int n){
        ft.assign(n+1,0);
    }
    int LSB(int S){
        return S&(-S);
    }
    int rsq(int b){
        int sum=0;
        while(b){
            sum+=ft[b];
            b-=LSB(b);
        }
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b)-(a==1? 0 : rsq(a-1));
    }
    void adjust(int k,int v){
        while(k<ft.sz()){
            ft[k]+=v;
            k+=LSB(k);
        }
    }
};

void solve(){
   int N,CASE=0;
   while(cin>>N){
       if(!N) break;
       if(CASE) cout<<"\n";
       cout<<"Case "<<++CASE<<":\n";
       FenwickTree FT(200001);
       veci a;
       for(int i=1;i<=N;i++){
           int t;
           cin>>t;
           a.pb(t);
           FT.adjust(i,t);
       }
       str op;
       while(cin>>op){
           if(op=="END") break;
           int x,y;
           cin>>x>>y;
           if(op=="M"){
               cout<<FT.rsq(x,y)<<'\n';
           }
           elif(op=="S"){
               int v=y-a[x-1];
               a[x-1]=y;
               FT.adjust(x,v);
           }
       }
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