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
    veci a;
    for(int i=0;i<3;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    sort(a.begin(),a.end());
    int c=0;
    for(int i=1;i<3;i++){
        if(a[i]==a[i-1]) c++;
    }
    if(c==2) {
        cout<<"YES\n";
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
    }
    elif(c==0) cout<<"NO\n";
    elif(c==1){
        if(a[1]==a[2]) {
            cout<<"YES\n";
            cout<<1<<" "<<a[0]<<" "<<a[2]<<"\n";
        }
        else cout<<"NO\n";
    }
    
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