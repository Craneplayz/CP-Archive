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
    str a;
    cin>>a;
    int c1=0,n;
    n=a.lng;
    for(int i=1;i<n;i++)
        if(isalpha(a[i-1])&&isdigit(a[i])) c1++;

    if(c1==1){
        str b,c;
        veci d;
        int sum=0;
        for(char i:a){
            if(isalpha(i)) b.pb(i);
            else c.pb(i);
        }
        for(char i:b) d.pb(i-'A'+1);
        n=d.size()-1;
        for(int i=n;i>=0;i--) sum+=d[i]*pow(26,n-i);
        cout<<"R"<<c<<"C"<<sum<<"\n";
    }
    elif(c1==2){
        str b,c,e;
        int r,c2,c3;
        veci d;
        for(int i=1;i<n;i++){
            if(a[i]=='C')  {
                r=i;
                break;
            }
            else b.pb(a[i]); 
        }
        for(int i=r+1;i<n;i++) c.pb(a[i]);
        c2=stoi(c);
        while(true){
            d.pb(c2%26);
            if(c2%26==0) c2--;
            if(c2/26==0) break;
            c2/=26;
        }
        n=d.size();
        for(int i=0;i<n;i++){
            if(d[i]==0) d[i]=26;
            d[i]--;
        } 
        for(int i=n-1;i>=0;i--) e.pb(d[i]+'A');
        cout<<e<<b<<'\n';
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