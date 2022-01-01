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
   int n,q;
   cin>>n>>q;
   str s;
   cin>>s;
   int k=0;
   for(int i=2;i<n;i++)
       if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c') k++;

   for(int i=0;i<q;i++){
       int pos; char c;
       cin>>pos>>c;
       pos--;
       int b1=0,b2=0;
       if(s[pos-2]=='a'&&s[pos-1]=='b'&&s[pos]=='c') b1++;
       if(s[pos-1]=='a'&&s[pos]=='b'&&s[pos+1]=='c') b1++;
       if(s[pos]=='a'&&s[pos+1]=='b'&&s[pos+2]=='c') b1++;
       s[pos]=c;
       if(s[pos-2]=='a'&&s[pos-1]=='b'&&s[pos]=='c') b2++;
       if(s[pos-1]=='a'&&s[pos]=='b'&&s[pos+1]=='c') b2++;
       if(s[pos]=='a'&&s[pos+1]=='b'&&s[pos+2]=='c') b2++;
       if(b1>b2) k--;
       elif(b1<b2) k++;
       cout<<k<<'\n';
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