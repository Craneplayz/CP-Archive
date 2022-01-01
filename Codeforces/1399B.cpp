#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define pii pair<int,int>
#define pllll pair<long long,long long>
#define psi pair<string,int>
#define veci vector<int>
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

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ll n,c=0,min1=INT_MAX,min2=INT_MAX;
    vecpllll a;
    cin>>n;
    
    for(ll i=0;i<n;i++){
        pllll temp;
        cin>>temp.first;
        min1=min(temp.first,min1);
        temp.second=0;
        a.pb(temp);
    }

    for(ll i=0;i<n;i++){
        ll temp;
        cin>>temp;
        min2=min(temp,min2);
        a[i].second=temp;
    }

    for(ll j=0;j<n;j++){
        if(a[j].first>min1&&a[j].second>min2){
            ll d1=a[j].first-min1;
            ll d2=a[j].second-min2;
            ll dp=min(d1,d2);
            c+=dp;
            a[j].first-=dp;
            a[j].second-=dp;
        }
        if(a[j].first>min1){
            c+=a[j].first-min1;
             a[j].first=min1;
        }
        if(a[j].second>min2){
            c+=a[j].second-min2;
            a[j].second=min2;
        }
    }

    cout<<c<<'\n';
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