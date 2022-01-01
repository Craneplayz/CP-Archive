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
#define vecl vector<long long>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpllll vector<pair<long long,long long>>
#define vecpsi vector<pair<string,int>>
#define vecb vector<bool>
#define vecb2 vector<vector<bool>>
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
   int n,m,k;   //y,x -> [n][m]
   cin>>n>>m>>k;
   veci2 a;
   for(int i=0;i<n;i++){
       veci t1;
       for(int j=0;j<m;j++){
           int t2;
           cin>>t2;
           t1.pb(t2);
       }
       a.pb(t1);
   }
   for(int h=0;h<k;h++){
       int ball;
       cin>>ball;
       ball--;
       for(int i=0;i<n;i++){
           if(a[i][ball]==1) {
              a[i][ball]=2;
               ball++;
               i--;
           }
           elif(a[i][ball]==3) {
              a[i][ball]=2;
               ball--;
               i--;
           }
       }
       cout<<ball+1<<' ';
   }
   cout<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}