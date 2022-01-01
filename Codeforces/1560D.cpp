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

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

vecs d;

void memo(){
    ll i=1;
    for(int j=0;j<60;j++){
        d.pb(to_string(i));
        i*=2;
    }
}

int check1(str a,str i){
   int c=0;
   for(int k=0;k<a.lng;k++){
       if(a[k]!=i[k]){
           a.erase(k,1);
           k--;
           c++;
       }
   } 
   if(i.lng>a.lng) c+=i.lng-a.lng;
   return c;
}

int checkstep(str a){
    for(str i:d) if(a==i) return 0;
    int m1=a.lng+1;
    for(str i:d)
         m1=min(check1(a,i),m1);
    return m1;
}

void solve(){
    int n;
    cin>>n;
    str a=to_string(n);
    cout<<checkstep(a)<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memo();
   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}