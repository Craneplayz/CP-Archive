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
   vecs a;
   str t;
   int m=-1;
   while(getline(cin,t)) {
       m=max((int)t.length(),m);
       a.pb(t);
   }
   for(int i=0;i<m+2;i++) cout<<"*";
   cout<<"\n";
   int n=a.size();
   int k3=1;
   for(int i=0;i<n;i++){
       cout<<"*";
       int k1=m-a[i].length(),k2;
       if(k1&1) {
           k1/=2;
           k2=k1;
           if(k3) k2++;
           else k1++;
           k3=(k3+1)%2;
       }
       else{
           k1/=2;
           k2=k1;
       }
       for(int j=0;j<k1;j++) cout<<" ";
       cout<<a[i];
       for(int j=0;j<k2;j++) cout<<" ";
       cout<<"*";
       cout<<'\n';
   }
   for(int i=0;i<m+2;i++) cout<<"*";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}