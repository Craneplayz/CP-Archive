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
   while(cin>>n){
      

      veci a(n);
      for(int i=0;i<n;i++) cin>>a[i];
      sort(all(a));
      int money;
      cin>>money;

      pii ans;
      int dist=INT_MAX;
      for(int i=0;i<n;i++){

         int L=i+1,R=n-1;
         int b=INT_MAX;
         while(L<=R){
            int mid=(L+R)/2;
            if(a[mid]==money-a[i]){
               b=mid;
               break;
            }
            elif(a[mid]>money-a[i]) R=mid-1;
            else L=mid+1;
         }


         if(b!=INT_MAX && abs(money-2*a[i])<dist){
            dist=abs(money-2*a[i]);
            ans={a[i],a[b]};
         }
      }


      cout<<"Peter should buy books whose prices are "<<ans.first<<" and "<<ans.second<<".\n";
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