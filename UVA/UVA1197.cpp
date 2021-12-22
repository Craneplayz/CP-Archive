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

struct UnionFind{
    veci p,rank,num;
    UnionFind(int N){
        p.assign(N,0);
        rank.assign(N,0);
        num.assign(N,1);
        for(int i=0;i<N;i++) p[i]=i;
    }

    int FindSet(int i){
        if(p[i]==i) return i;
        return p[i]=FindSet(p[i]);
    }

    bool isSameSet(int i,int j){
        return FindSet(i)==FindSet(j);
    }

    void UnionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=FindSet(i),y=FindSet(j);
            if(rank[x]>rank[y]) {p[y]=x; num[x]+=num[y];}
            else{
                p[x]=y;
                num[y]+=num[x];
                if(rank[x]==rank[y]) rank[y]++;
            } 
        }
    }

};

void solve(){
   int n,m;
   while(cin>>n>>m){
      if(n==0&&m==0) break;
      UnionFind Un(n);
      for(int i=0;i<m;i++){
          int N;
          cin>>N;
          int prev;
          for(int j=0;j<N;j++){
              int k;
              cin>>k;
              if(!j) prev=k;
              else{Un.UnionSet(prev,k); prev=k;}
          }
      }
      for(int i=0;i<n;i++) Un.FindSet(i);
      cout<<Un.num[Un.p[0]]<<'\n';
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