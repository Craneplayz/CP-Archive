/*
ID: zhixian3
TASK: ride
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

//Declarations
#define lg long
#define ll long long
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecb vector<bool>
#define str string

//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    str a,b;
    fin>>a>>b;
    veci c,d;
    for(int i=0;i<a.lng;i++) c.pb(a[i]-'A'+1);
    for (int i=0;i<b.lng;i++) d.pb(b[i]-'A'+1);
    int k1=c[0],k2=d[0];
    for(int i=1;i<c.size();i++){
        k1*=c[i];
        k1%=47;
    }
    for(int i=1;i<d.size();i++){
        k2*=d[i];
        k2%=47;
    }
    if(k1==k2) fout<<"GO\n";
    else fout<<"STAY\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}