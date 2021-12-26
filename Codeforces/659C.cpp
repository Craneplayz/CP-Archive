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
    veci a,b;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    int i=0,j=0;
    while(++i){
        if(m-i<0) {
            b[b.size()-1]+=m;
            for(;j<n;j++)
                if(b[b.size()-1]==a[j]) {
                    b[b.size()-1]--;
                    break;
                }
            break;
        }
        if(i==a[j]) {
            if(m==a[j]) break;
            j++;
            continue;
        }
        else{
            m-=i;
            b.pb(i);
        }
    }
    
    cout<<b.size()<<endl;
    for(int i:b) cout<<i<<' ';
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