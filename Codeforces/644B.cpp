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
#define pl pair<long long,long long>
#define psi pair<string,int>
#define qi queue<int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecl vector<long long>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpl vector<pair<long long,long long>>
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

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    ll n,b,c=0,j=0;
    cin>>n>>b;
    vecpl a;
    vecl d(n,0);
    for(int i=0;i<n;i++){
       ll t1,t2;
       cin>>t1>>t2;
       a.pb({t1,t2});
    }
    if(n==1) cout<<a[0].first+a[0].second;
    else{
    queue<pl> q; //queue
    ll i=1,t=a[0].first; //current time
    ll ta=t+a[0].second; //next complete time
    ll tb=ta;  //complete time
    while(true){
        if(i>=n||a[i].first>=ta){
           t=ta;
           d[j]=t;
           if(c) {
           c--;
           //extract data from queue
           ta=q.front().second;
           j=q.front().first;
           q.pop(); 
           }
        }
        if(i<n){
            t=a[i].first;
            if(tb<t) tb=t;
            if(c<b){ //check if queue is full
            tb+=a[i].second;  //record complete time
            q.push({i,tb}); //{index,complete time}
            c++;
            }
            else d[i]=-1;
        }
        if(i>=n&&q.empty()) break;
        i++;
    }
    d[j]=ta; //last element from queue
    for(ll k:d) cout<<k<<" ";
    cout<<"\n";
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