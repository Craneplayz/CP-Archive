#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
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
    int n,m;
    bool b=false;
    cin>>n>>m;
    veci a={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int l=a.size();
    for(int i=0;i<l;i++){
        if(a[i]==n) b=a[i+1]==m;
    }
    if(b) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}