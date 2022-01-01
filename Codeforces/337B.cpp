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

ifstream fin ("test.in");
ofstream fout ("test.out");

pair<long long, long long> toFrac(double x){
    double INT=floor(x);
    double frac=x-INT;

    const ll Prec = 1e9;

    ll d=round(frac*Prec);

    ll gcd_=gcd(d,Prec);

    ll numerator = d/gcd_;
    ll denominator = Prec/gcd_;

    return {numerator,denominator};
}

double gcd(double a,double b){
    if (b<=eps) return a;
    return gcd(b, fmod(a,b));
}

void solve(){
   double a,b,c,d;
   cin>>a>>b>>c>>d;
   ll Area=c*d;
   //a=c
   double w1=c,h1=(c*b)/a;
   ll W1=a*c,H1=c*b;
   //b=d
   double w2=(d*a)/b,h2=d;
   ll W2=d*a,H2=d*b;

   double a1,a2;
   if(w1>c||h1>d) a1=0;
   else a1=w1*h1;

   if(w2>c||h2>d) a2=0;
   else a2=w2*h2;

   ll ans;
   if(a1>=a2){
       ans=W1*H1;
       Area*=a*a;
   }
   else{
       ans=W2*H2;
       Area*=b*b;
   }

   ans=Area-ans;
   if(ans==0) cout<<"0/1\n";
   else{
        ll gcd_=gcd(ans,Area);
        cout<<ans/gcd_<<"/"<<Area/gcd_<<"\n";
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