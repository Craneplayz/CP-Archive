#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
typedef list<int> lsi;
typedef map<int,int> mii; 
typedef map<int,char> mic; 
typedef map<char,int> mci;
typedef map<string,int> msi; 
typedef map<string,pair<int,int>> mspii; 
typedef map<string,map<int,int>> msmii;
typedef pair<int,int> pii;
typedef pair<long long,long long> pl;
typedef pair<string,int> psi;
typedef queue<int> qi;
typedef vector<int> veci;
typedef vector<int>::iterator itveci; 
typedef vector<vector<int>> veci2;
typedef vector<long long> vecl;
typedef vector<vector<long long>> vecl2;
typedef vector<float> vecf;
typedef vector<vector<float>> vecf2;
typedef vector<string> vecs;
typedef vector<vector<string>> vecs2;
typedef vector<pair<int,int>> vecpii;
typedef vector<pair<long long,long long>> vecpll;
typedef vector<pair<string,int>> vecpsi;
typedef vector<bool> vecb;
typedef vector<vector<bool>> vecb2;
typedef string str;

//Functions
#define elif else if
#define lng length
#define size sz
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    ll l1=abs(r2-r1),l2=abs(c1-c2);
    cout<<(int)(l1!=0)+(int)(l2!=0)<<" "; //rook
    ll b1=1,b2=1;
    if(r1%2==0&&c1%2) b1=0;
    elif(r1%2&&c1%2==0) b1=0;
    if(r2%2==0&&c2%2) b2=0;
    elif(r2%2&&c2%2==0) b2=0;
    if(b1!=b2) cout<<0<<" ";
    elif(l1==l2) cout<<1<<' ';
    else cout<<2<<" "; 
    cout<<max(l1,l2)<<'\n';

}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   solve();
   
   return 0;
}