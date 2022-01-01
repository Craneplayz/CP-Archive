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
#define vecll vector<long long>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
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

vecll a,b;
ll DEF,ATK,n;

void solve(){
   ll sum=0;
   cin>>n;
   for(ll i=0;i<n;i++){
       ll t;
       cin>>t;
       a.pb(t);
       sum+=t;
   }
   ll t;
   cin>>t;
   sort(a.begin(),a.end());
   for(ll i=0;i<n;i++) b.pb(sum-a[i]);
   while(t--){
       cin>>DEF>>ATK;
       if(a[n-1]<DEF) cout<<DEF-a[n-1]+max((ll)0,ATK-b[n-1])<<'\n';
       elif(a[0]>DEF) cout<<max((ll)0,ATK-b[0])<<'\n';
       else{
       ll k=upper_bound(a.begin(),a.end(),DEF-1)-a.begin();
       if(k==0) cout<<max((ll)0,DEF-a[k])+max((ll)0,ATK-b[k])<<'\n';
       else cout<<min(max((ll)0,DEF-a[k])+max((ll)0,ATK-b[k]),max((ll)0,DEF-a[k-1])+max((ll)0,ATK-b[k-1]))<<'\n';
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