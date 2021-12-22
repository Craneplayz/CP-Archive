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

struct Obj{
    int strength;
    int bonus;
    Obj(){
        strength=0;
        bonus=0;
    }
};

void solve(){
    int s,n;
    bool b=false;
    cin>>s>>n;
    vector<Obj> data;
    Obj obj;
    for(int i=0;i<n;i++){
        data.pb(obj);
        cin>>data[i].strength>>data[i].bonus;
    }

    sort(data.begin(),data.end(),
    [](const Obj & a, const Obj & b)->bool{
        return (a.strength<b.strength);
    });

    for(int i=0;i<n;i++){
        if(s>data[i].strength){
            s+=data[i].bonus;
            b=true;
        }
        else {
            b=false;
            break;
        }
    }

    if(b) cout<<"YES\n";
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