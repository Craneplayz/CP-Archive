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
    str s;
    cin>>s;
    int l=s.lng;
    if(l<5) cout<<"NO\n";
    else{
        bool a,b,c,d,e;
        a=b=c=d=e=false;
        for(int i=0;i<l;i++){
            if(d&&s[i]=='o') e=true;
            elif(c&&s[i]=='l') d=true;
            elif(b&&s[i]=='l') c=true;
            elif(a&&s[i]=='e') b=true;
            elif(s[i]=='h') a=true;
        }
        if(e) cout<<"YES\n";
        else cout<<"NO\n";
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