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
#define str string

//Functions
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    str a;
    cin>>a;
    int n=a.length();
    if(n<7) cout<<"no\n";
    else{
        //declare
        int loc,cnt=0,k=0;

        //find first 1-digit
        for(int i=0;i<n;i++)
            if(a[i]=='1') {
             k++;
             loc=i;
                break;
            }
        if(k==0) cout<<"no\n";
        else{
            //Check if has 6 0-digit
            for(int i=loc+1;i<n;i++)
                if(a[i]=='0') cnt++;

            //Output
            if(cnt>=6) cout<<"yes\n";
            else cout<<"no\n";
        }
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