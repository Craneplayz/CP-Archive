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

void solve(){
    int n,c;
    bool d= false;
    veci a,b;

    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
        b.pb(0);
    }

    for(int i=0;i<n;i++) b[a[i]-1]++;

    for(int i=0;i<n;i++)
        if(b[i]==1) {
            d=true;
            c=i+1;
            break;
        }

    if(!d) cout<<-1<<endl;
    else{
        for(int i=0;i<n;i++)
            if(a[i]==c) {
                cout<<i+1<<endl;
                break;
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