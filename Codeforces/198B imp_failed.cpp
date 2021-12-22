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
    int n,k,i=0,j=0,m=-1;
    vecs a(2,"");
    bool b3=false,c=true;
    cin>>n>>k>>a[0]>>a[1];
    while(true){
        if(i+1>n||i+k>n) break;
          m++;
        if(i<m){
            if(n==6978) cout<<"@\n";
            c=false;
            break;
        }
        bool b1=true,b2=true;
        int h=(j+1)%2;
        if(b3||(i+1<=n&&a[j][i+1]=='X')) b1=false;
        if(i+k<=n&&a[h][i+k]=='X') b2=false;
        if(b2) {
            i+=k;
            j=h;
            b3=false;
        }
        elif(b1) i++;
        else {
            b3=true;
            if(i-1<0||a[j][i-1]=='X') {
                c=false;
                break;
            }
            i--;
        }
    }
    if(c) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}