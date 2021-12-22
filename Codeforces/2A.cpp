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
    int n,r=0,max=0;
    cin>>n;
    msi m;
    vecpsi a;
    vecs b;
    for(int i=0;i<n;i++){
        psi temp;
        cin>>temp.first>>temp.second;
        m[temp.first]=0;
        a.pb(temp);
    }
    for(int i=0;i<n;i++)
        m[a[i].first]+=a[i].second;
    
    for(psi i:a)
        if(m[i.first]>max)  max=m[i.first];
    
    for(psi i:a)
        if(m[i.first]==max) b.pb(i.first);
    
    int l=b.size();
    if(l==1) cout<<b[0]<<endl;
    else {
        msi mp;
        for(str i:b) mp[i]=0;
        for(int i=0;i<n;i++){
            bool k=false;
            for(int j=0;j<l;j++){
                if(a[i].first==b[j]) {
                    k=true;
                    break;
                }
            }
            if(!k) continue;
            mp[a[i].first]+=a[i].second;
            if(mp[a[i].first]>=max) {
                cout<<a[i].first<<endl;
                break;
            }
        }
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