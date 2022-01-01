#include <bits/stdc++.h>
using namespace std;

//Declarations
#define dqi deque<int>
#define lg long
#define ll long long
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
    int n,c=0;
    cin>>n;
    veci a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]){
            if(a[i+1]<=2*a[i]) continue;
            else {
                int m=a[i];
                while(!(a[i+1]<=2*m)){
                    c++;
                    m*=2;
                }
            }
        }
        else{
            if(a[i]<=2*a[i+1]) continue;
            else {
                int m=a[i+1];
                while(!(a[i]<=2*m)){
                    c++;
                    m*=2;
                }
            }
        }
    }
    cout<<c<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}