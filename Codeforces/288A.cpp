#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back
#define veci vector<int>
#define ll long long

void solve(){
    int c=0;
    veci vec;

    //Input
    for(int i=0;i<4;i++){
        int temp;
        cin>>temp;
        vec.pb(temp);
    }

    //Algo
    sort(vec.begin(),vec.end());
    for(int i=1;i<4;i++)
        if(vec[i-1]==vec[i]) c++;
    
    cout<<c<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}