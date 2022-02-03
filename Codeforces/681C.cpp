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
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

void solve(){
   int n;
   cin>>n;
   priority_queue<int,veci,greater<int>> pq;
   vecs ans;
   for(int i=0;i<n;i++){
      str op,ansi="";
      cin>>op;
      int tar=-1;
      if(op!="removeMin") cin>>tar;
      if(op=="insert"){
         pq.push(tar);
         ansi+=op+" "+to_string(tar);
         ans.pb(ansi);
      }
      elif(op=="getMin"){
         while(!pq.empty()&&pq.top()<tar){
            pq.pop();
            ans.pb("removeMin");
         }
         if(pq.empty()){
            pq.push(tar);
            ans.pb("insert"+str(" ")+to_string(tar));            
         }
         if(pq.top()>tar){
            pq.push(tar);
            ans.pb("insert"+str(" ")+to_string(tar));
         }
         ans.pb("getMin"+str(" ")+to_string(tar));
      }
      else{
         if(pq.empty()){
            pq.push(1);
            ans.pb(str("insert")+str(" ")+to_string(1));
         }
         ans.pb("removeMin");
         pq.pop();
      }
   }
   cout<<ans.sz()<<'\n';
   for(str s:ans)
      cout<<s<<"\n";
   
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}