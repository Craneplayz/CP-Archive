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
    int n,c=0;
    cin>>n;
    vecs a;
    for(int i=0;i<n;i++){
        str b;
        cin>>b;
        a.pb(b);
    }
    for(int i=0;i<n;i++){
        c=0;
        for(int j=0;j<5;j++){
            if(a[i][j]=='O') c++;
            if(a[i][j]=='|') {
                if(c==2) {
                    a[i][j-1]='+';
                    a[i][j-2]='+';
                    break;
                }
                else c=0;
            }
            if(j==4) {
                if(c==2) {
                    a[i][j-1]='+';
                    a[i][j]='+';
                    break;
                }
                else c=0;
            }
        }
        if(c) break;
    }
    if(c==2) {
        cout<<"YES\n";
        for(int i=0;i<n;i++)
            cout<<a[i]<<'\n';
    }
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