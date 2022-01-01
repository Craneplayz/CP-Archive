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

void solve(){
    int n,c=0;
    bool k=false;
    cin>>n;
    veci a,b;
    vecpii d;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.pb(t);
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        b.pb(t);
    }
    int i=0,j=0;
    while(i<n&&j<n){
        if(a[i]>b[i]&&a[j]<b[j]) {
            a[i]--;
            a[j]++;
            d.pb(make_pair(i+1,j+1));
            c++;
        }
        if(a[i]<=b[i]) i++;
        if(a[j]>=b[j]) j++;
    }
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) {
            k=true;
            break;
        }
    if(k) cout<<"-1\n";
    else {
        cout<<c<<'\n';
        for(pii i:d)
            cout<<i.first<<" "<<i.second<<'\n';
    }
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