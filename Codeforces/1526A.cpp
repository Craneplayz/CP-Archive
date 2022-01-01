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
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecs vector<string>
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

void solve(){
    int n;
    cin>>n;
    dqi a;
    for(int i=0;i<2*n;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    a.pb(a[0]);
    a.pb(a[1]);
    for(int i=1;i<2*n+1;i++){
        if((a[i-1]+a[i+1])==2*a[i]) swap(a[i],a[i-1]);
    }
    for(int i=1;i<2*n+1;i++){
        if((a[i-1]+a[i+1])==2*a[i]) swap(a[i],a[i-1]);
    }
    for(int i=0;i<2*n;i++) cout<<a[i]<<" ";
    cout<<endl;
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