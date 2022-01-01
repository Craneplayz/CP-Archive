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
#define vecs2 vector<vector<string>>
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

void solve(){
    int n,m;
    cin>>n>>m;
    vecs a,b;
    for(int i=0;i<n;i++){
        str temp;
        cin>>temp;
        a.pb(temp);
        b.pb(temp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                if(i&1){
                    if(j&1){
                    a[i][j]='W';
                    b[i][j]='R';
                    } 
                    else{
                    a[i][j]='R';
                    b[i][j]='W';
                        }
                }
                else{
                    if(j&1){
                    a[i][j]='R';
                    b[i][j]='W';
                    } 
                    else{
                    a[i][j]='W';
                    b[i][j]='R';
                    }
                }
            }
        }
    }
    bool ka=true,kb=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==a[i][j+1]) ka=false;
            if(b[i][j]==b[i][j+1]) kb=false;
            if((!ka)&&(!kb)) break;
        }
        if((!ka)&&(!kb)) break;
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n-1;i++){
            if(a[i][j]==a[i+1][j]) ka=false;
            if(b[i][j]==b[i+1][j]) kb=false;
            if((!ka)&&(!kb)) break;
        }
        if((!ka)&&(!kb)) break;
    }
    if(ka) {
        cout<<"YES\n";
        for(str i:a)
            cout<<i<<endl;
    }
    elif(kb){
        cout<<"YES\n";
        for(str i:b)
            cout<<i<<endl;
    }
    else cout<<"NO\n";
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