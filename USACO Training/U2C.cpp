/*
ID: zhixian3
TASK: namenum
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
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict;
    dict.open("dict.txt");
    str a,s;
    fin>>a;
    mci m;
    m['A']=2;   m['B']=2;   m['C']=2;
    m['D']=3;   m['E']=3;   m['F']=3;
    m['G']=4;   m['H']=4;   m['I']=4;
    m['J']=5;   m['K']=5;   m['L']=5;
    m['M']=6;   m['N']=6;   m['O']=6;
    m['P']=7;   m['R']=7;   m['S']=7;
    m['T']=8;   m['U']=8;   m['V']=8;
    m['W']=9;   m['X']=9;   m['Y']=9;
    vecs d;
    while(getline(dict,s)){
        str k="";
        bool b=false;
        if(s.lng!=a.lng) continue;
        for(int i=0;i<a.lng;i++){
            if(m[s[i]]!=a[i]-'0') {
                b=true;
                break;
            }
            else k.pb(s[i]);
        }
        if(b) continue;
        else d.pb(k);
    }
    if(d.empty()) fout<<"NONE\n";
    else for(str s:d) fout<<s<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}