#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define lsi list<int>
#define mii map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define mspii map<string,pair<int,int>>
#define msmii map<string,map<int,int>>
#define pii pair<int,int>
#define pllll pair<long long,long long>
#define psi pair<string,int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecs vector<string>
#define vecpii vector<pair<int,int>> 
#define vecpllll vector<pair<long long,long long>>
#define vecpsi vector<pair<string,int>>
#define vecb vector<bool>
#define str string


//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()

char c1='*';

bool check(str a){
    bool c=true,b=true;
    ll k=a.lng;
    if(k==1) return true;
    elif(k==2&&a[0]!='?'&&a[0]!=a[1]) return true;
    for(char i:a) 
        if(i!='?'){
            b=false;
            break;
        }
    if(b) return true;
    ll c3=0;
    for(int i=k-1;i>0;i--){
        if(!c) break;
        if(a[i]!='?') c1=a[i];
        else {
            c3++;
            if(a[i-1]!='?'&&c1!='*') {
                if(c3&1) c=(c1==a[i-1]);
                else c=(c1!=a[i-1]);
            }
        }
        if(a[i-1]!='?') c3=0;
    }
    return c;
}

void solve(){
    str s;
    cin>>s;
    ll n=s.lng;
    ll c=0;
    bool m=true,p=true;
    for(char i:s){
        if(i!='?'){
            m=false;
            break;
        }
    }
    str sp=s;
    reverse(sp.begin(),sp.begin());
    sp.ppb;
    bool pp;
    for(char i:sp){
        if(i!='?'){
            pp=false;
            break;
        }
    }
    for(ll i=0;i<n;i++){
        if(s[i]=='?'||s[i]==s[i-1]||s[i]==s[i+1]){
            p=false;
            break;
        }
    }
    if(m||p) cout<<n*(n+1)/2<<endl;
    elif(pp) cout<<n*(n+1)/2+n<<endl;
    else{
        for(int i=0;i<n;i++){
        str b="";
        bool k;
        for(int j=0;j<n;j++){
            if(i+j>n-1) break;
            b.pb(s[i+j]);
            ll l=b.lng-1;
            if(j==0) k=check(b);
            if(b[l-1]=='?'&&b[l]!='?') k=check(b);
            elif(b[l-1]!='?'&&b[l]==b[l-1]) k=false;
            if(k) c++;
            else break;
        }
        c1='*';
    }    
    cout<<c<<endl;
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