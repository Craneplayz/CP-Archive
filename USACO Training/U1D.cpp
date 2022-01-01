/*
ID: zhixian3
TASK: beads
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

//Declarations
#define lg long
#define ll long long
#define psi pair<string,int>
#define veci vector<int>
#define veci2 vector<vector<int>>
#define vecs vector<string> 
#define vecpsi vector<pair<string,int>>
#define vecb vector<bool>
#define str string

//Functions
#define elif else if
#define lng length()
#define pb push_back
#define ppb pop_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n,l,c,k=0,cw=0,maxi=0;
    deque<int> a;
    //map<int,char> debug;
    char c1,c2;
    str o;
    fin>>n>>o;
    int j=n;
    for(int i=0;i<2;i++) a.pb(0);

    for(int i=n-1;i>-1;i--)
        if(o[i]!='w') {
            c1=o[i];
            break;
        }

    while(j--)
        if(o[0]=='w'||o[0]==c1){
            o+=o[0];
            o.erase(o.begin());
        }
        else break;

    for(int i=0;i<n;i++){
        //debug.insert(make_pair(i,o[i]));
        if(o[i]!='w') c2=o[i];
        if(o[i]=='r') a[k]++;
        elif(o[i]=='b') a[k]++;
        elif(o[i]=='w'){
           a[k]++;
           if(o[i-1]==o[i+1]&&o[i+1]=='w') cw++;
           elif(i!=n-1&&o[i-1]!='w'&&o[i+1]!='w'&&o[i-1]!=o[i+1]) cw++;
        }
        if(i!=n-1&&o[i+1]!='w'&&c2!=o[i+1]) {
            if(k==0) {
                a[1]+=cw;
                a[0]-=cw;
                cw=0;
            }
            k++;
        }
        if(k==2||i==n-1) {
           l=a[0]+a[1];
           a.pop_front();
           k--;
           a.pb(0);
           if(o[i]=='w') {
               a[1]+=cw;
               a[0]-=cw;
            }
           maxi=max(l,maxi);
           cw=0;
        }
    }
    //Output    
    fout<<maxi<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}