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

int n;
veci temp(1000,0);
veci2 coord(1000,temp);
vecb b;

void DFS(int x,int y){
    for(int j=0;j<1000;j++){
        if(coord[x][j]&& !b[coord[x][j]-1]){
            b[coord[x][j]-1]=true;
            DFS(x,j);
        }
        if(coord[j][y]&& !b[coord[j][y]-1]){
            b[coord[j][y]-1]=true;
            DFS(j,y);
        }
    }
}

void solve(){
    int c=0;
    cin>>n;
    for(int i=0;i<n;i++) b.pb(false);
    for(int i=1;i<=n;i++){
        int t1,t2;
        cin>>t1>>t2;
        coord[t1-1][t2-1]=i; 
    }
    for(int i=0;i<1000;i++)//x
        for(int j=0;j<1000;j++)//y
            if(coord[i][j]&&!b[coord[i][j]-1]){
                b[coord[i][j]-1]=true;
                c++;
                DFS(i,j); //by x
            }
    cout<<c-1<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}