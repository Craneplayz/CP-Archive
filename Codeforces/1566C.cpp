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
#define ppf pop_front()s

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    int n,sum=0,k0=0,k1=0;
    str a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) {
            sum+=2+k0;
            k1=0;
            k0=0;
        }
        else{
            if(a[i]=='0') k0++;
            else k1++;
            if(k0==1&&k1==1) {
                sum+=2;
                k0--;
                k1--;
            }
            elif(k0==2) {
                sum+=1;
                k0--;
            }
            if(k1==2) k1--;
            if(k0==1&&i==n-1) sum+=1;
        }
    }
    cout<<sum<<'\n';
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