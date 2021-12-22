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

void solve(){
   int n,m,sum=0;
   cin>>n>>m;
   vecpii a;
   for(int i=0;i<m;i++){
       pii p;
       cin>>p.second>>p.first;
       a.pb(p);
   }
   sort(a.begin(),a.end());
   for(int i=m-1;i>=0;i--){
       if(n>a[i].second) {
           sum+=a[i].second*a[i].first;
           n-=a[i].second;
       }
       else{
           sum+=n*a[i].first;
           break;
       }
   }
   cout<<sum<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}