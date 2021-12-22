#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define ll long long
#define lsi list<int>
#define mii map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define msi map<string,int>
#define mspii map<string,pair<int,int>>
#define msmii map<string,map<int,int>>
#define pii pair<int,int>
#define pl pair<long long,long long>
#define psi pair<string,int>
#define qi queue<int>
#define veci vector<int>
#define itveci vector<int>::iterator
#define veci2 vector<vector<int>>
#define vecl vector<long long>
#define vecl2 vector<vector<long long>>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
#define vecpii vector<pair<int,int>> 
#define vecpll vector<pair<long long,long long>>
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

void solve(){
   int n,M=INT_MAX;
   cin>>n;
   veci2 a(n+1,veci(n+1,0));
   vecb b(n+1,0);
   for(int i=0;i<n;i++){
       int t1,t2,t3;
       cin>>t1>>t2>>t3;
       a[t1][t2]=t3;
   }
   veci ka;
   int h=0;
   for(int i=1;i<n+1;i++){
       int c=0;
       for(int j=1;j<n+1;j++){
            if(a[i][j]) {
                c++;
                ka.pb(j);
            }
        }
       if(c==2) {
           b[i]=1;
           h=i;
           break;
       }
       ka.clear();
    }
    if(!h) cout<<"0\n";
    else{
    vecb b0=b;
    for(int i=0;i<2;i++){
        int k=ka[i],m=0;
        b=b0;
        while(true){
            if(!b[k]){
                b[k]=1;
                int c1=k;
                for(int j=1;j<n+1;j++){
                   if(a[k][j]&&(!b[j])){
                       k=j;
                       break;
                   }
                }
                if(k==c1) for(int j=1;j<n+1;j++){
                    if(a[j][k]&&(!b[j])){
                       m+=a[j][k];
                       k=j;
                       break;
                    }
                }
                
            }  
            else{
                if(!a[k][h]) m+=a[h][k];
                break;
            } 
        }
        M=min(m,M);
    }
    cout<<M<<"\n";
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