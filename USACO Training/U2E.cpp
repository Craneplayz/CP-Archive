/*
ID: zhixian3
TASK: dualpal
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

str dict;

str base(int a, int B){
    str c;
    while(a){
        char k=dict[a%B];
        c.pb(k);
        a/=B;
    }
    reverse(c.begin(),c.end());
    return c;
}

bool isPalin(str a){
    str b=a;
    reverse(b.begin(),b.end());
    if(a==b) return true;
    else return false;
}

void generateBase(int B){
    for(int i=0;i<B;i++){
        if(i<=9) dict.pb(char(i+'0'));
        else dict.pb(char('A'+i-10));
    }
}

void solve(){
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    generateBase(10);
    int n,S;
    fin>>n>>S;
    int k=0;
    
    while(true){
        S++;
        bool c=false;
        int j=0;
        for(int i=2;i<=10;i++){
            str a=base(S,i);
            if(isPalin(a)) j++;
            if(j==2){
                fout<<S<<endl;
                c=true;
                break;
            }      
        }
        if(c) k++;
        if(k==n) break;
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