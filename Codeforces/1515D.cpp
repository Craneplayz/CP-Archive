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
    int n,l,r,c=0;
    cin>>n>>l>>r;
    veci L(n,0),R(n,0);
    bool b=true;
    for(int i=0;i<l;i++){
        int t;
        cin>>t;
        L[t-1]++;
    }
    for(int i=0;i<r;i++){
        int t;
        cin>>t;
        R[t-1]++;
    }
    for(int i=0;i<n;i++){
        int t=min(L[i],R[i]);
        L[i]-=t;
        R[i]-=t;
        l-=t;
        r-=t;
        
    }
    for(int i=0;i<n;i++){
        if(l>r&&L[i]>1){
            c++;
            l-=2;
            L[i]-=2;
            i--;
        }
        if(l<r&&R[i]>1){
            c++;
            r-=2;
            R[i]-=2;
            i--;
        }
    }
    if(l!=r) c+=abs(l-r)/2+(l+r)/2;
    else c+=l;
    cout<<c<<'\n';
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