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
    str a;
    cin>>a;
    int c=0,n=a.lng;
    bool b0=0,b1=0,ba=0,bb=0;
    for(int i=0;i<a.lng;i++){
        if(a[i]=='0') b0=1;
        elif(a[i]=='1') b1=1;
    }
    if(!b0) cout<<"0\n";
    elif(!b1) cout<<"1\n";
    else {
        for(int i=0;i<a.lng;i++){
            if(a[i]=='1'&&i>0&&i<n-1) {
                if(a[i-1]!=a[i]) ba=1;
                if(ba&&a[i]!=a[i+1]) bb=1;
            }
            if(ba&&bb) c++;
        }
        if((!c)&&b0) c++;
        cout<<min(2,c)<<"\n";
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