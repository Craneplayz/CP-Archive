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

void solve(){
    int n;
    cin>>n;
    veci vec;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vec.pb(temp);
    }
    if(n==1) cout<<"1"<<endl;
    else{
    sort(vec.begin(),vec.end());
    int a=0,b=vec[n-1],c=1;
    vec.ppb;
    for(int i:vec) a+=i;
    for(int i=n-2;i>-1;i--) {
        if(a>=b){
            b+=vec[i];
            a-=vec[i];
            c++;
        }
    }
    if(a==b) c++;
    cout<<c<<endl;
}}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}