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
typedef vector<pair<long long,long long>> vecpll;
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

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
   str get;
   vector<pair<string,string>>a,RETURN;
   map<str,str> ms;
   while(getline(cin,get)){
       if(get=="END") break;
       str t="";
       pair<str,str> s;
       bool b=1;
       for(int i=0;i<get.len();i++){
           t+=get[i];
           if(b&&i&&get[i]=='\"'){
               s.second=t;
               t="";
               i+=3;
               b=0;
           }
           if(i==get.len()-1) s.first=t;
       }
       a.pb(s);
       ms[s.second]=s.first;
   }
   sort(a.begin(),a.end());
   msi mp;
   int k=0;
   for(pair<str,str>i:a) mp[i.second]=k++;
   vecs BORROW;
   veci b(k,1);
   while(getline(cin,get)){
       if(get=="SHELVE"){
           sort(RETURN.begin(),RETURN.end());
           for(str i:BORROW) b[mp[i]]=0;
           for(pair<str,str> is:RETURN){
               str i=is.second;
               cout<<"Put "<<i;
               b[mp[i]]=1;
                int index=-1;
                for(int j=mp[i]-1;j>-1;j--)
                if(b[j]) {
                    index=j;
                    break;
                }
                if(index==-1){
                  cout<<" first\n";
                  continue;
                }
                str s=a[index].second;
                cout<<" after "<<s<<'\n';
            }
            cout<<"END\n";
            BORROW.clear();
            RETURN.clear();
            continue;
        }
       if(get=="END") break;
       str t="";
       bool br;
       for(int i=0;i<get.len();i++){
           t+=get[i];
           if(t=="BORROW") {br=1;t="";i++;}
           elif(t=="RETURN") {br=0;t="";i++;}
       }
       if(br) BORROW.pb(t);
       else RETURN.pb({ms[t],t});
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