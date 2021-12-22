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
#define len length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
// #define cin fin
// #define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    int ori[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>ori[i][j];
    int arr[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) arr[i][j]=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            arr[i][j]+=ori[i][j];
            if(i) arr[i-1][j]+=ori[i][j];
            if(j) arr[i][j-1]+=ori[i][j];
            if(i!=2) arr[i+1][j]+=ori[i][j];
            if(j!=2) arr[i][j+1]+=ori[i][j];
        }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]%=2;
            cout<<(arr[i][j]+1)%2;
        }
        cout<<'\n';
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