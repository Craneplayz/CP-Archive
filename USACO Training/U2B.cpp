/*
ID: zhixian3
TASK: transform
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

bool same(vecs a,vecs b,int n){
    bool c=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]!=b[i][j]){
                c=false;
                break;
            }
    return c;
}

bool rot90(vecs a,vecs b,int n){
    vecs c;
    for(int i=0;i<n;i++){
        str s;
        for(int j=n-1;j>-1;j--)
            s+=a[j][i];
        c.pb(s);
    }
    return same(b,c,n); 
}

bool rot180(vecs a,vecs b,int n){
    vecs c;
    for(int i=n-1;i>-1;i--){
        str s;
        for(int j=n-1;j>-1;j--)
            s+=a[i][j];
        c.pb(s);
    }
    return same(b,c,n); 
}

bool rot270(vecs a,vecs b,int n){
    vecs c;
    for(int i=n-1;i>-1;i--){
        str s;
        for(int j=0;j<n;j++)
            s+=a[j][i]; //a[R][C]
        c.pb(s);
    }
    return same(b,c,n); 
}

bool reflect(vecs a,vecs b,int n){
    vecs c;
    for(int i=0;i<n;i++){
        str s;
        for(int j=n-1;j>-1;j--)
            s+=a[i][j]; //a[R][C]
        c.pb(s);
    }
    return same(b,c,n); 
}

bool combine(vecs a, vecs b,int n){
    vecs c;
    for(int i=0;i<n;i++){
        str s;
        for(int j=n-1;j>-1;j--)
            s+=a[i][j]; //a[R][C]
        c.pb(s);
    }
    bool d1,d2,d3;
    d1=rot90(c,b,n);
    d2=rot180(c,b,n);
    d3=rot270(c,b,n);
    return (d1||d2||d3);
}

void solve(){
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin>>n;
    vecs a,b;
    for(int i=0;i<n;i++){
        str temp;
        fin>>temp;
        a.pb(temp);
    }
    for(int i=0;i<n;i++){
        str temp;
        fin>>temp;
        b.pb(temp);
    }
    if(rot90(a,b,n)) fout<<1<<'\n';
    elif(rot180(a,b,n)) fout<<2<<'\n';
    elif(rot270(a,b,n)) fout<<3<<'\n';
    elif(reflect(a,b,n)) fout<<4<<'\n';
    elif(combine(a,b,n)) fout<<5<<'\n';
    elif(same(a,b,n)) fout<<6<<'\n';
    else fout<<7<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}