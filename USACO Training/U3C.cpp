/*
ID: zhixian3
TASK: crypt1
LANG: C++                 
*/

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
#define cin fin
#define cout fout

//ofstream fout ("test.out");
//ifstream fin ("test.in");

ofstream fout ("crypt1.out");
ifstream fin ("crypt1.in");

veci a;

bool check(int k){
    bool b=true;
    while(k){
        if(find(a.begin(), a.end(), k%10) == a.end()) b=false;
        if(!b) break;
        k/=10; 
    }
    return b;
}

void solve(){
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.pb(t);
    }
    for(int i1=0;i1<n;i1++)
        for(int i2=0;i2<n;i2++)
            for(int i3=0;i3<n;i3++){
                int A=a[i1]*100+a[i2]*10+a[i3];
                for(int i4=0;i4<n;i4++)
                    for(int i5=0;i5<n;i5++){
                        int B=a[i4]*10+a[i5];
                        int AB1=A*a[i4],AB2=A*a[i5];
                        if(AB1/1000>=1||AB2/1000>=1) continue;
                        elif(!check(AB1)||!check(AB2)) continue;
                        if(check(A*B)) c++;
                    }
            }
    cout<<c<<"\n";         
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}