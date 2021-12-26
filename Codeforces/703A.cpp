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
    int n,a,b,c1=0,c2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b) c1++;
        else if(a<b) c2++;
    }
    if(c1>c2) cout<<"Mishka\n";
    elif(c1<c2) cout<<"Chris\n";
    elif(c1==c2) cout<<"Friendship is magic!^^\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}