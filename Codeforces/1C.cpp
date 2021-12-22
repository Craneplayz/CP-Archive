#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define lsi list<int>
#define mii map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define mspii map<string,pair<int,int>>
#define msmii map<string,map<int,int>>
#define pii pair<int,int>
#define pllll pair<long long,long long>
#define psi pair<string,int>
#define qi queue<int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpllll vector<pair<long long,long long>>
#define vecpsi vector<pair<string,int>>
#define vecb vector<bool>
#define str string


//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

#define pi 3.14159265358979323846

//Distance
double distance(double x1, double y1, double x2, double y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//Heron
double heron(double a,double b, double c){
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

//GCD for float
double gcdF(double a, double b){
  if (b<0.001) return a;
  return gcdF(b, fmod(a,b));
}

void solve(){
   double ax,ay,bx,by,cx,cy;
   cin>>ax>>ay>>bx>>by>>cx>>cy;
   double a=distance(cx,cy,bx,by);
   double b=distance(ax,ay,cx,cy);
   double c=distance(ax,ay,bx,by);
   double S=heron(a,b,c);
   double r=a*b*c/(4*S);
   
   double a1=2*asin(a/(2*r)), a2=2*asin(b/(2*r)), a3=2*pi-a1-a2;
   double d=gcdF(a1,gcdF(a2,a3));
   double A=(pi*sin(d)*r*r)/d;

   cout<<fixed<<setprecision(6)<<A<<'\n';
  
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}