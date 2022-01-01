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
#define elif else if 
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    int a,b,n;
    char centre=' ';
    bool check=false;
    cin>>a>>b;
    str final,c,d;
    cin>>final;
    n=final.length();

    if(n==1){
        if(final=="?"){
            if(a) final="0";
            else final="1";
            cout<<final<<endl;
        }        
        elif(final=="0"&& a==0) cout<<-1<<endl;
        elif(final=="1"&& b==0) cout<<-1<<endl;
        else cout<<final<<endl;
    }
    else{
        //Splitting Array
        for(int i=0;i<n;i++) {
            if(n&1) {
                if(i+1==(n+1)/2) centre=final[i];
                else if(i+1<(n+1)/2) c.pb(final[i]);
                else d.pb(final[i]);
            }
            else{
                if(i+1<=n/2) c.pb(final[i]);
                else d.pb(final[i]);
            }
        }

        //Considering centre
        if(centre=='?') {
            if(a&1) {
                centre='0';
                a--;
            }
            else{
                centre='1';
                b--;
            }
        }
        //Outcome:a=b

        //Count '0's and '1's in array
        for(char car:final){
            if(car=='0') a--;
            else if (car=='1') b--;
        }

        //Reverse Right array
        reverse(d.begin(),d.end());

        //Algo
        int np=c.length();
        for(int i=0;i<np;i++){
            if(c[i]=='?'||d[i]=='?'){    //If one of which is '?'
                if(isdigit(c[i])){       //If left is digit and right is '?'
                    d[i]=c[i];
                    if(d[i]=='1') b--;        //If digit is '1'
                    else a--;            //If digit is '0'
                }
                elif(isdigit(d[i])){       //If left is '?' and right is digit
                    c[i]=d[i];
                    if(c[i]=='1') b--;        //If digit is '1'
                    else a--;            //If digit is '0'
                }                    //If both is '?'
            }
            else if(c[i]!=d[i]){
                check=true;
                break;
            }
         }

        //When left & right are both '?'
        for(int i=0;i<np;i++){
            if(c[i]=='?'&&d[i]=='?'){
                if(a>=b) {
                    c[i]='0';
                    d[i]='0';
                    a-=2; 
                }
                else{
                    c[i]='1';
                    d[i]='1';
                    b-=2; 
                }
            }
        }
    
        if(a!=0||b!=0) check=true;

        //Output
        if(check) cout<<"-1"<<endl;
        else{
            reverse(d.begin(),d.end());
            if(n&1) cout<<c<<centre<<d;
            else cout<<c<<d;
            cout<<endl;
        }
    }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}