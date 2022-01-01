/*
ID: zhixian3
TASK: milk
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
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int m,n,c=0;
    fin>>m>>n;
    vecpii p;
    for(int i=0;i<n;i++){
        pii temp;
        fin>>temp.first>>temp.second;
        p.pb(temp);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        if(m==0) break;
        elif(p[i].second<=m) {
            c+=p[i].first*p[i].second;
            m-=p[i].second;
        }
        else {
            c+=p[i].first*m;
            break;
        }
    }
    fout<<c<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}