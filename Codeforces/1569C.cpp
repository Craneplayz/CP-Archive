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

const ll m=998244353;

void solve(){
    ll n;
    cin>>n;
    vecl a;
    for(ll j=0;j<n;j++){
        ll t;
        cin>>t;
        a.pb(t);
    }
    sort(a.begin(),a.end());
    ll m1=1,m2=1;
    for(ll i=n-1;i>-1;i--){
         if(m2==1&&a[i]==a[i-1]) m1++;
         elif(a[i-1]==a[n-1]-1) m2++;
         else break;
    }
    ll ans=1,b=1;
    for(ll i=1;i<=n;i++){
        ans=ans*i%m;
        if(i!=m2) b=b*i%m; 
    }
    if(m1>=2) cout<<ans<<'\n';
    else cout<<(ans-b+m)%m<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}