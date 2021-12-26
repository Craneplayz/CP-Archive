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
    int y,x;
    cin>>y>>x;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++)
            if(i&1) cout<<'#';
            else{
                if((i/2)%2) {
                    if(j==x) cout<<'#';
                    else cout<<'.';
                }
                else {
                    if(j==1) cout<<'#';
                    else cout<<'.';
                }
            }
        cout<<endl;
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