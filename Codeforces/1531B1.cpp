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
#define vecb2 vector<vector<bool>>
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
    int n,c=0,s=0;
    cin>>n;
    veci a,b;
    vecb2 k;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        //if(temp1==temp2) s++;
        a.pb(temp1);
        b.pb(temp2);
        vecb e;
        for(int j=i+1;j<n;j++)
            e.pb(false);
        k.pb(e);
    }
    for(int i=0;i<n;i++){
        int h=0;
        for(int j=i+1;j<n;j++){
            if(b[i]==b[j])  k[i][h]=true;
            elif(b[i]==a[j])  k[i][h]=true;
            elif(a[i]==b[j])  k[i][h]=true;
            elif(a[i]==a[j])  k[i][h]=true;
            h++;
        }
    }

    for(vecb i:k)
        for(bool j:i)
            if(j) c++;

    cout<<c<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}