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
    int n;
    cin>>n;
    if(n&1) cout<<9<<" "<<n-9<<"\n";
    else cout<<4<<" "<<n-4<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}