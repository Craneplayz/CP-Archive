/*
ID: zhixian3
TASK: combo
LANG: C++                 
*/

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
#define cin fin
#define cout fout

//ofstream fout ("test.out");
//ifstream fin ("test.in");

ofstream fout ("combo.out");
ifstream fin ("combo.in");

void solve(){
   int n,sum;
   cin>>n;
   veci2 a(3,veci());
   veci c(3,0);
   for(int i=0;i<6;i++){
       int t,k=i%3;
       cin>>t;
       a[k].pb(t);
       if(t==1) a[k].pb(n);
       else a[k].pb(t-1);
       if(t==2) a[k].pb(n);
       elif (t==1) a[k].pb(n-1);
       else a[k].pb(t-2);
       if(t==n) a[k].pb(1);
       else a[k].pb(t+1);
       if(t==n-1) a[k].pb(1);
       elif(t==n) a[k].pb(2);
       else a[k].pb(t+2);
   }
   for(int i=0;i<3;i++){
       sort(a[i].begin(),a[i].end());
       for(int j=0;j<a[i].size()-1;j++)
           if(a[i][j]==a[i][j+1]){
               c[i]++;
           }
   }
    if(n<=5) sum=n*n*n;
    else sum=250-c[0]*c[1]*c[2];
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