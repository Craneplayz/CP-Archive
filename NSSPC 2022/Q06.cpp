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
#define rall(x) x.rbegin(),x.rend()

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #ifndef ONLINE_JUDGE
// #define cin fin
// #define cout fout
// #endif

ifstream fin ("test.in");
ofstream fout ("test.out");

void solve(){
   double m,c;
   cin>>m>>c;
   double det = (-2-m)*(-2-m)-4*(1)*(-3-c);
   double x1 = (-(-2-m)+sqrt(det))/(2*1);
   double x2 = (-(-2-m)-sqrt(det))/(2*1);
   if(x2>x1) swap(x2,x1);
   double y1=m*x1+c;
   double y2=m*x2+c;
   if(det<0) cout<<"No intersection\n";
   elif(det>0){ 
      cout<<"Two intersections\n";
      cout << fixed << setprecision(7)<<x1<<", "<<y1<<"\n";
      cout << fixed << setprecision(7)<<x2<<", "<<y2<<"\n";
   }
   else{
      cout<<"One intersection\n";
      cout << fixed << setprecision(7)<<x1<<", "<<y1<<"\n";
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