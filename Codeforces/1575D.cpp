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
#define vecl vector<long long>
#define vecf vector<float>
#define vecf vector<float>
#define vecf2 vector<vector<float>>
#define vecs vector<string>
#define vecs2 vector<vector<string>>
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

//Debug
//#define cin fin
//#define cout fout

ofstream fout ("test.out");
ifstream fin ("test.in");

vecs num={"00","25","50","75"};

void solve(){
    str a;
    cin>>a;
    int n=a.size();
    if(n==1){
        if(a[0]=='0'||a[0]=='_'||a[0]=='X') cout<<"1\n";
        else cout<<"0\n";
    }
    elif(a[0]=='0') cout<<"0\n";
    else{
        int c1=0;
        bool c3=a[0]=='X';
        str b=a.substr(n-2,2),c="";
        for(str i:num){
            bool b1=0,b2=0;
            char c2='@';
            if(b[0]==i[0]) b1=1;
            elif(b[0]=='_') b1=1;
            elif(b[0]=='X'&&!(c3&&i[0]=='0')){
                b1=1;
                c2=i[0];
            }
            if(b[1]==i[1]) b2=1;
            elif(b[1]=='_') b2=1;
            elif(c3&&i[1]=='0') b2=0;
            elif(b[1]=='X'&&(c2=='@'||i[1]==c2)) {
                b2=1;
                c2=i[1];
            }

            if(b1&&b2) {
                c1++;
                if(i=="00"&&a.size()==2) c1--;
            }
            if(c2!='@') c+=c2;
        }
        int k=c.lng;
        for(int i=0;i<n-2;i++){
            if(a[i]=='_') {
                if(i) c1*=10;
                else c1*=9;
            }
            elif(!k&&a[i]=='X'){
                if(i) c1*=10;
                else c1*=9;
                k++;
            }
        }
        cout<<c1<<'\n';
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