#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Declarations
#define ll long long
#define veci vector<int>
#define str string

//Functions
#define pb push_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    str a;
    int check =0,q=0;
    cin >> a;

    int n=a.length();
    for(int i=1;i<n;i++)
        if(a[i]>='a'&&a[i]<='c'&&a[i-1]>='a'&&a[i-1]<='c')
            if(a[i]==a[i-1]) {
                check++;
                break;
            }   
    
    for(int i=0;i<n;i++)
        if(a[i]!='?'){
                q++;
                break;
            } 

    if(check) cout<<"-1"<<endl;
    else if(!q){
        for(int i=1;i<=n;i++){
            if(i%3==0) cout<<'a';
            else if(i%3==1) cout<<'b';
            else cout<<'c';
        }
        cout<<'\n';
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]=='?') {
                if(!i) { //i=0
                    if(a[i+1]=='a') a[i]='b';
                    else if(a[i+1]=='b') a[i]='c';
                    else a[i]='a';
                }
                else if(i>0&&i<n-1){ //0<i<n-1
                    if(a[i-1]=='a'){
                        if(a[i+1]=='b') a[i]='c';
                        else a[i]='b';
                    }
                    else if(a[i-1]=='b'){
                        if(a[i+1]=='c') a[i]='a';
                        else a[i]='c';
                    }
                    else if(a[i-1]=='c'){
                        if(a[i+1]=='a') a[i]='b';
                        else a[i]='a';
                    }
                }
                else{ //i==n-1
                    if(a[i-1]=='a') a[i]='b';
                    else if(a[i-1]=='b') a[i]='c';
                    else a[i]='a';
                }
            }
        }
        cout<<a<<endl;
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