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
    int n;
    str a;
    veci c(4,0);
    cin>>n>>a;
    bool b=false;
    if(a.substr(0,4)=="2020") b=true;
    elif(a.substr(n-4,n)=="2020") b=true;
    if(b) cout<<"YES\n";
    else{
        int k=0;
        str d="2020";
        for(int i=0;i<n;i++){
            if(k>3) break;
            elif(a[i]==d[k]){
                c[k]++;
                k++;
            }
            else break;
        }
        k=3;
        for(int i=n-1;i>-1;i--){
            if(k<0) break;
            elif(a[i]==d[k]){
                c[k]++;
                k--;
            }
            else break;
        }
        for(int i:c) 
            if(i) b=true;
            else {
                b=false;
                break;
            }
        if(b) cout<<"YES\n";
        else cout<<"NO\n";
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