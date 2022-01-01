/*
ID: zhixian3
TASK: barn1
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define pii pair<int,int>
#define pllll pair<long long,long long>
#define psi pair<string,int>
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecs vector<string>
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

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M,S,C;
    fin>>M>>S>>C;
    int sum=C;
    dqi a,b;
    for(int i=0;i<C;i++){
        int temp;
        fin>>temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<C-1;i++){
        if(a[i]!=a[i+1]-1) b.pb(a[i+1]-a[i]-1); 
    }
    int k=b.size();
    sort(b.begin(),b.end());
    for(int i=k;i>M-1;i--){
            sum+=b[0];
            b.ppf;
    }
    fout<<sum<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}