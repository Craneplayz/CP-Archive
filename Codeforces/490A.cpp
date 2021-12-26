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
#define psi pair<string,int>
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecs vector<string> 
#define vecpsi vector<pair<string,int>>
#define vecpii vector<pair<int,int>>
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
    int n,k;
    cin>>n;
    vecpii a,b,c;
    for(int i=1;i<=n;i++){
        pii d;
        cin>>d.first;
        d.second=i;
        if(d.first==1) a.pb(d);
        elif(d.first==2) b.pb(d);
        else c.pb(d);
    }
    
    k=min(a.size(),min(b.size(),c.size()));

    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<a[i].second<<" ";
        cout<<b[i].second<<" ";
        cout<<c[i].second<<"\n";
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