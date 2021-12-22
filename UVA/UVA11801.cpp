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
#define lng length
#define size sz
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
#define cin fin
#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   int CASE;
   cin>>CASE;
   cout<<"Case "<<CASE<<": ";
   int N,M;
   cin>>N>>M;
   veci x,a,b,c,d;
   for(int i=0;i<N;i++){
       int tx,ta,tb,tc,td;
       cin>>tx>>ta>>tb>>tc>>td;
       x.pb(tx);
       a.pb(ta);
       b.pb(tb);
       c.pb(tc);
       d.pb(td);
   }
   int opsum=0;
   veci choice;
   for(int i=0;i<N;i++){
       double r1=b[i]/a[i],r2=d[i]/c[i];
       if(r1>r2){
           choice.pb(1);
           int k=(x[i]+a[i]-1)/a[i];
           opsum+=k*b[i];
       }
       elif(r1<r2){
           choice.pb(1);
           int k=(x[i]+a[i]-1)/a[i];
           opsum+=k*b[i];
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