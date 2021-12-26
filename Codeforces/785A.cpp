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
    int n,sum=0;
    cin>>n;
    str a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a=="Tetrahedron") sum+=4;
        elif(a=="Cube") sum+=6;
        elif(a=="Octahedron") sum+=8;
        elif(a=="Dodecahedron") sum+=12;
        elif(a=="Icosahedron") sum+=20;
    }
    cout<<sum<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}