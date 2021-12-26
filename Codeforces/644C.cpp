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
   int n,k=0;
   cin>>n;
   map<str,set<str>> m1;
   for(int i=0;i<n;i++){
       str t;
       cin>>t;
       int c=0,j=0;
       for(int i=0;i<t.size();i++){
           if(t[i]=='/') c++;
           if(c==3)  {
               j=i-7;
               break;
           }
       }
       if(j==0) j=t.size()-7;
       if(m1.find(t.substr(7,j))==m1.end()) m1[t.substr(7,j)]=set<str>();
       if(c) m1[t.substr(7,j)].insert(t.substr(j+7,t.size()-j-7));
       else m1[t.substr(7,j)].insert("*");
   }
   map<set<str>,vecs> m2;
   for(map<str, set<str>>::iterator i=m1.begin(); i!=m1.end();++i){
      if(m2.find(i->second)==m2.end()) m2[i->second]=vecs();
      m2[i->second].pb(i->first);
   }
   for(map<set<str>,vecs>::iterator i=m2.begin(); i!=m2.end();++i){
      if((int)i->second.size()==1) k++;
   }
   cout<<m2.size()-k<<"\n";
   for(map<set<str>,vecs>::iterator i=m2.begin(); i!=m2.end();++i){
      if((int)i->second.size()>1){
      for(str j:i->second) cout<<"http://"<<j<<" ";
      cout<<"\n";
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