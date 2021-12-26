#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

//Declarations
#define lg long
#define ll long long
#define veci vector<int>
#define vecb vector<bool>
#define str string

//Functions
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    str a;
    while(true){
        char car;
        if(car=='}') break;
        cin>>car;
        a.pb(car);
    }
    vecb b;
    bool bo=false;
    int c=0,n;
    for(int i=0;i<26;i++) b.pb(bo);
    for(int i=0;i<a.length();i++){
        if(isalpha(a[i])){
            n=a[i]-'a';
            b[n]=true;
        }  
    }
    for(bool i:b){
        if(i) c++;
    }
    cout<<c<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}