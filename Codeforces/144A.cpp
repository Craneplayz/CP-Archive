#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stdc++.h>
using namespace std;

//Declarations
#define ll long long
#define veci vector<int>

//Functions
#define pb push_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    int n,big=0,small=INT_MAX,locb,locs,sum=0;
    veci vec;

    //Input
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vec.pb(temp);
    }

    locb=n;
    locs=0;

    //Searching for min & max, Recording their indices
    for(int i=0;i<n;i++){ 
        if((i<locb&&big==vec[i])||big<vec[i]){
            big=vec[i];
            locb=i;
        }
        if((i>locs&&small==vec[i])||small>vec[i]){
            small=vec[i];
            locs=i;
        }
    }

    //Summing up
    n--;
    if(locs<locb) sum--; //if big & small meets
    locs=n-locs; //locs to end of queue
    sum+=locs+locb;

    cout<<sum<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}