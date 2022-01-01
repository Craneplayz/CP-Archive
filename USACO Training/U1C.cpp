/*
ID: zhixian3
TASK: friday
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
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n,day,sum=0,j=13;
    fin>>n;
    veci week;
    for(int i=0;i<7;i++) week.pb(0);
    for(int i=1900;i<1900+n;i++){
        int day;
        if(i%400==0) day=366;
        elif(i%100==0) day=365;
        elif(i%4==0) day=366;
        else day=365;
        int k=1;
        while(k<13){
            if(j%7) week[j%7-1]++;
            else week[6]++;
            if(day==366&&k==2) j+=29;
            else if(k==2) j+=28;
            elif(k==1||k==3||k==5||k==7||k==8||k==10||k==12) j+=31;
            else j+=30;
            k++;
        }
    }
    fout<<week[5]<<" "<<week[6]<<" "<<week[0]<<" "<<week[1]<<" ";
    fout<<week[2]<<" "<<week[3]<<" "<<week[4]<<"\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}