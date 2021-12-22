#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
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
    int n,sum=0;
    cin>>n;
    veci a,b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
        cin>>temp;
        b.pb(temp);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]==b[j]) sum++;
    
    cout<<sum<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}