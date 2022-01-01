/*
ID: zhixian3
TASK: milk2
LANG: C++                 
*/

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
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n,c=0,time,timemax=0,time0=0;
    fin>>n;
    vecpii a;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        fin>>temp1>>temp2;
        pii b=make_pair(temp1,1);
        pii c=make_pair(temp2,-1);
        a.pb(b);
        a.pb(c);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<a.size();i++){
        if(a[i].first==a[i-1].first&&a[i].second!=a[i-1].second){
            a.erase(a.begin()+i);
            a.erase(a.begin()+i-1);
            i--;
        }
    }
    int time1=a[0].first,time2;
    for(int i=1;i<a.size();i++){
        time2=a[i].first;
        c+=a[i-1].second;
        if(c>0){
            time=time2-time1;
            timemax=max(timemax,time);
        }
        elif(c==0){
            time1=a[i-1].first;
            time=time2-time1;
            time0=max(time0,time);
            time1=time2;
        }
    }
    fout<<timemax<<' '<<time0<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}