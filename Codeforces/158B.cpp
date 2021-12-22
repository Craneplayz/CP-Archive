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

void solve(){
    int n,k,sum=0;
    cin>>n;
    veci a(4,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[temp-1]++;
    }

    k=min(a[0],a[2]);
    sum+=k;
    a[0]-=k; a[2]-=k;
    k=min(a[0]/2,a[1]);
    sum+=k;
    a[0]-=2*k; a[1]-=k;
    k=min(a[0],a[1]);
    a[0]-=k; a[1]-=k;
    sum+=k;

    k=a[1]/2;
    sum+=k;
    a[1]-=2*k;
    k=a[0]/4;
    if(a[0]%4) k++; 

    sum+=k+a[1]+a[2]+a[3];
    cout<<sum<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}