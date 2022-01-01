#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
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
typedef vector<vector<int>> veci2;
typedef vector<long long> vecl;
typedef vector<vector<long long>> vecl2;
typedef vector<float> vecf;
typedef vector<vector<float>> vecf2;
typedef vector<string> vecs;
typedef vector<vector<string>> vecs2;
typedef vector<pair<int,int>> vecpii;
typedef vector<pair<long long,long long>> vecpl;
typedef vector<pair<string,int>> vecpsi;
typedef vector<bool> vecb;
typedef vector<vector<bool>> vecb2;
typedef string str;

//Functions
#define elif else if
#define len length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) x.begin(),x.end()

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    str a,s;
    cin>>a>>s;
    //s-a=b
    int i=a.len()-1,j=s.len()-1;
    str b="";
    str t1="",t2="";
    int k1,k2;
    while(i>-1||j>-1){
        if(i<0){
            while(j>-1) b+=s[j--];
            break; 
        }
        if(j<0){cout<<"-1\n"; return;}
        t1+=a[i--]; t2+=s[j--];
        k1=stoi(t1); k2=stoi(t2);
        if(k2-k1<0){
            if(j>-1) t2+=s[j--];
            else {cout<<"-1\n"; return;}
            reverse(all(t2));
            k2=stoi(t2);
            if(k2-k1<0||k2-k1>=10) {cout<<"-1\n"; return;}
            else{
                b.pb((k2-k1)+'0');
                t1=""; t2="";
            }
        }
        else{
            b.pb((k2-k1)+'0');
            t1=""; t2="";
        }
    }
    reverse(all(b));
    for(int i=0;i<b.sz();i++){
        if(b[i]=='0'){ b=b.substr(1,INT_MAX); i--;}
        else break;
    }
    cout<<b<<"\n";
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