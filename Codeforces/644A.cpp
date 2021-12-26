#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define ll long long
#define lsi list<int>
#define mii map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define mspii map<string,pair<int,int>>
#define msmii map<string,map<int,int>>
#define pii pair<int,int>
#define pl pair<long long,long long>
#define psi pair<string,int>
#define qi queue<int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecl vector<long long>
#define vecl2 vector<vector<long long>>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpll vector<pair<long long,long long>>
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
   int n,a,b;
   cin>>n>>a>>b;
   int k=1;
   veci2 d(a,veci(b,0));
   for(int i=0;i<a;i++){
       for(int j=0;j<b;j++) {
           d[i][j]=k++;
           if(k>n) break;
        }
       if(!(b%2)&&i%2) reverse(d[i].begin(),d[i].end());
       if(k>n) break;
   }
   if(k<=n) cout<<"-1\n";
   else for(veci i:d){
       for(int j:i) cout<<j<<" ";
       cout<<"\n";
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