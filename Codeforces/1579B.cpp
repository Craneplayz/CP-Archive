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

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    int n;
    cin>>n;
    veci a,b,c,d,e;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.pb(t);
    }
    b=a;
    sort(b.begin(),b.end());
    int c1=0,c2=n;
    for(int i=n-1;i>-1;i--){
        if(a[i]!=b[i]){
            int k1=find(a.begin(),a.end(),b[i])-a.begin();
            c.pb(k1+1);
            d.pb(c2--);
            e.pb(1);
            a.erase(a.begin()+k1);
        }
        else c2--;
    }
    int n2=c.size();
    cout<<n2<<'\n';
    for(int i=0;i<n2;i++){
        cout<<c[i]<<" "<<d[i]<<" "<<e[i]<<'\n';
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