/*
ID: zhixian3
TASK: gift1
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

//Declarations
#define lg long
#define ll long long
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
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<str,int> a;
    vecs d;
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        str b;
        fin>>b;
        a.insert(make_pair(b,0));
        d.pb(b);
    }
    for(int i=0;i<n;i++){
        str b;
        int m,k;
        fin>>b>>m>>k;
        if(k==0) continue;
        a[b]-=m-m%k;
        int mp=m/k;
        for(int i=0;i<k;i++){
            str c;
            fin>>c;
            a[c]+=mp;
        }
   }
    for(str e:d) fout<<e<<" "<<a[e]<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}