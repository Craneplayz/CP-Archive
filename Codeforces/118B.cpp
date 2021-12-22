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
    veci a;
    cin>>n;
    for(int i=0;i<=n;i++) a.pb(i);
    for(int i=0;i<n+1;i++){
        for(int j=n-i;j>0;j--) cout<<"  ";
        for(int j=0;j<i+1;j++) {
            cout<<a[j];
            if(i) cout<<' ';
        }
        for(int j=i-1;j>=0;j--) {
            cout<<a[j];
            if(j) cout<<' ';
        }
        cout<<'\n';
    }
    for(int i=n-1;i>-1;i--){
        for(int j=n-i;j>0;j--) cout<<"  ";
        for(int j=0;j<i+1;j++) {
            cout<<a[j];
            if(i) cout<<' ';
        }
        for(int j=i-1;j>=0;j--) {
            cout<<a[j];
            if(j) cout<<' ';
        }
        cout<<'\n';
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