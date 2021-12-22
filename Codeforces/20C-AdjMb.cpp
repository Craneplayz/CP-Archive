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
#define vecb2 vector<vector<bool>>
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

int n,m;
veci2 graph;
veci d,p;
vecb visit;

void dijk(int s){
    d[s]=0;
    p[s]=s;
    for(int i=1;i<=n;i++){
        int a=-1,min=100000;
        for(int j=1;j<=n;j++)
            if(!visit[j]&&d[j]<min){
                a=j;
                min=d[j];
            }
        if(a==-1 || min==100000) break;
        visit[a]=true;
        for(int b=1;b<=n;b++){
            if(!visit[b] &&d[a]+graph[a][b]<d[b]){
                d[b]=d[a]+graph[a][b];
                p[b]=a;
            }
        }
    }
}
void print_path(int k){
    if(k!=p[k])
        print_path(p[k]);
    cout<<k<<" ";
}

void solve(){
   cin>>n>>m;
   for(int i=0;i<n+1;i++){
       graph.pb(veci(n+1,100000));
       d.pb(100000);
       p.pb(0);
       visit.pb(false);
   }
       
   for(int i=0;i<m;i++){
       int A,B,W;
       cin>>A>>B>>W;
       graph[A][B]=min(graph[A][B],W);
       graph[B][A]=min(graph[B][A],W);
   }
    dijk(1);
    if(d[n]==100000) cout<<"-1";
    else print_path(n);
    cout<<"\n";
    d.clear();
    visit.clear();
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}