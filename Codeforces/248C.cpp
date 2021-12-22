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

ifstream fin ("test.in");
ofstream fout ("test.out");

double ya1, ya2, yw, xb, yb, r,tar,yp,m1,y3;

int check(double val){
    yp=yw-r;
    m1=(yp-yb)/(val-xb);
    // double c1=yb-m1*xb;
    // double xp=(yp-c1)/m1;
    y3=2*yp-(yb-xb*(yp-yb)/(val-xb));
    if(abs(y3-tar)<1e-10) return 0;
    if(y3<tar) return 1;
    if(y3>tar) return 2;
    return 0;
}

void solve(){
   cin>>ya1>>ya2>>yw>>xb>>yb>>r;
   double hi=xb,lo=0,mid;
   tar=ya1+r;
   cout<<fixed<<setprecision(10);
   while(hi-lo>1e-10){
       mid=(hi+lo)/2;
       int c=check(mid);
       if(!c) break;
       elif(c==1) hi=mid;
       elif(c==2) lo=mid;
   }
   double chec=abs(-ya2+y3)/hypot(m1,1);
   if(chec-r<=1e-10) cout<<"-1\n";
   else cout<<mid<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}