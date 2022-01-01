#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
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
#define vecl2 vector<vector<long long>>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpll vector<pair<long long,long long>>
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
    str a;
    bool b=1;
    cin>>n>>a;
    for(int i=1;i<n;i++)
        if(a[i]!=a[i-1]){
            b=0;
            break;
        }
    int k=n/2;
    if(b) cout<<1<<" "<<2*k<<" "<<1<<" "<<k<<"\n";
    else{
        int j;
        for(int i=0;i<n;i++)
            if(a[i]=='0') {
                j=i+1;
                break;
            }
        if(j<=k) cout<<j<<" "<<n<<" "<<j+1<<" "<<n<<"\n";
        else cout<<1<<" "<<j<<" "<<1<<" "<<j-1<<"\n";
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