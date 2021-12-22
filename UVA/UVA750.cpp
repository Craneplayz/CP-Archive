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

int N=8,k,x,y;
int row[9];

bool check(int r, int c){
    for(int i=1;i<c;i++){
        if(row[i]==r) return false;
        if(abs(i-c)==abs(row[i]-r)) return false;
    }
    if(abs(y-c)==abs(x-r)) return false;
    return true;
}

void back(int c){
    if(c==N+1){
        if(k<10) cout<<" "<<k++<<"      ";
        else cout<<k++<<"      ";
        for(int i=1;i<=N;i++){
            cout<<row[i];
            if(i!=N) cout<<" ";
        }
        cout<<"\n";
        return;
    }
    if(c==y){
        back(c+1);
        return;
    }
    for(int r=1;r<=N;r++){
        if(r!=x&&check(r,c)){
            row[c]=r;
            back(c+1);
        }
    }
}

void solve(){
   cin>>x>>y;
   memset(row,0,sizeof(row));
   row[y]=x;
   k=1;
   back(1);
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   int t;
   cin>>t;
   for(int i=0;i<t;i++){
     if(i) cout<<"\n";
     cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
     solve();
   }
   
    
   return 0;
}