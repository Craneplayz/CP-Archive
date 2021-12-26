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
#define vecb2 vector<vector<bool>>
#define str string


//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()

veci a,c;
int k,n;

void dfs(int i){
    if(c[i]==2) k=i;
    else {
        c[i]++;
        dfs(a[i]);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)
        a.pb(0);
    for(int i=0;i<n;i++){
        int t1;
        cin>>t1;
        a[i]=t1-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            c.pb(0);  
        dfs(i);
        cout<<k+1<<' ';
        c.clear();
    }
    cout<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}