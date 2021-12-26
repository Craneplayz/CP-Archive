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

//ofstream fout ("test.out");
//ifstream fin ("test.in");

void solve(){
    int V,E,c=0;
    cin>>V>>E;
    veci2 a(V+1,veci());
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int d=0;
    for(int i=1;i<V+1;i++){
        if(a[i].size()>d){
            c=i;
            d=a[i].size();
        }
    }
    vecb b(V+1,false);
    qi q;
    q.push(c);
    b[c]=true;
    while(!q.empty()){
       int u=q.front();
        q.pop();
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i];
            if(!b[v]){
                b[v]=true;
                q.push(v);
                cout<<u<<" "<<v<<endl;
            }
        }   
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