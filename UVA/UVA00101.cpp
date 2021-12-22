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

vector<stack<int>> a;
veci pos;

void Move1(int x,int y){
    if(pos[x]==pos[y]||x==y) return;
    while(a[pos[x]].top()!=x){
        int z=a[pos[x]].top();
        a[z].push(z);
        pos[z]=z;
        a[pos[x]].pop();
    }
    a[pos[x]].pop();
    while(a[pos[y]].top()!=y){
        int z=a[pos[y]].top();
        a[z].push(z);
        pos[z]=z;
        a[pos[y]].pop();
    }
    a[pos[y]].push(x);
    pos[x]=pos[y];
}

void Move2(int x,int y){
    if(pos[x]==pos[y]||x==y) return;
    while(a[pos[x]].top()!=x){
        int z=a[pos[x]].top();
        a[z].push(z);
        pos[z]=z;
        a[pos[x]].pop();
    }
    a[pos[x]].pop();
    a[pos[y]].push(x);
    pos[x]=pos[y];
}

void Pile1(int x,int y){
    if(pos[x]==pos[y]||x==y) return;
    while(a[pos[y]].top()!=y){
        int z=a[pos[y]].top();
        a[z].push(z);
        pos[z]=z;
        a[pos[y]].pop();
    }
    stack<int> b;
    while(a[pos[x]].top()!=x){
        int z=a[pos[x]].top();
        b.push(z);
        pos[z]=pos[y];
        a[pos[x]].pop();
    }
    a[pos[x]].pop();
    b.push(x);
    pos[x]=pos[y];
    while(!b.empty()){
        a[pos[y]].push(b.top());
        b.pop();
    }
}

void Pile2(int x,int y){
    if(pos[x]==pos[y]||x==y) return;
    stack<int> b;
    while(a[pos[x]].top()!=x){
        int z=a[pos[x]].top();
        b.push(z);
        pos[z]=pos[y];
        a[pos[x]].pop();
    }
    a[pos[x]].pop();
    b.push(x);
    pos[x]=pos[y];
    while(!b.empty()){
        a[pos[y]].push(b.top());
        b.pop();
    }
}

void solve(){
    int n;
    cin>>n;
    a.assign(n,stack<int>());
    pos.assign(n,0);
    for(int i=0;i<n;i++) {a[i].push(i); pos[i]=i;}
    str Op1,Op2;
    int x,y;
    while(cin>>Op1){
        if(Op1=="quit") break;
        cin>>x>>Op2>>y;
        if(Op1=="move"&&Op2=="onto") Move1(x,y);
        elif(Op1=="move"&&Op2=="over") Move2(x,y);
        elif(Op1=="pile"&&Op2=="onto") Pile1(x,y);
        elif(Op1=="pile"&&Op2=="over") Pile2(x,y);
    }
    for(int i=0;i<n;i++){
        cout<<i<<":";
        int k=0,s=a[i].sz();
        stack<int> q;
        while(!a[i].empty()) {q.push(a[i].top()); a[i].pop();} 
        while(!q.empty()){
            cout<<" ";
            cout<<q.top();
            q.pop();
        }
        cout<<"\n";
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
