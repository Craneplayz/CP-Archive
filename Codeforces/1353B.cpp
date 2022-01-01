#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define psi pair<string,int>
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecs vector<string> 
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
    int n,k,temp,sum=0;
    cin>>n>>k;
    veci a,b;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.pb(temp);
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        b.pb(temp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<k;i++) {
        if(a[i]<b[n-1-i]) swap(a[i],b[n-1-i]);
        else break;
    }

    for(int i:a) sum+=i;

    cout<<sum<<'\n';
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