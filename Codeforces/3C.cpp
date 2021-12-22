#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
typedef list<int> lsi;
typedef map<int,int> mii; 
typedef map<int,char> mic; 
typedef map<char,int> mci;
typedef map<string,int> msi; 
typedef map<string,pair<int,int>> mspii; 
typedef map<string,map<int,int>> msmii;
typedef pair<int,int> pii;
typedef pair<long long,long long> pl;
typedef pair<string,int> psi;
typedef queue<int> qi;
typedef vector<int> veci;
typedef vector<int>::iterator itveci; 
typedef vector<vector<int>> veci2;
typedef vector<long long> vecl;
typedef vector<vector<long long>> vecl2;
typedef vector<float> vecf;
typedef vector<vector<float>> vecf2;
typedef vector<string> vecs;
typedef vector<vector<string>> vecs2;
typedef vector<pair<int,int>> vecpii;
typedef vector<pair<long long,long long>> vecpl;
typedef vector<pair<string,int>> vecpsi;
typedef vector<bool> vecb;
typedef vector<vector<bool>> vecb2;
typedef string str;

//Functions
#define elif else if
#define len length
#define sz size
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

//Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

vecs T;

int check(char a){
    int count=0;
    
    //Check Hori
    for(int i=0;i<3;i++){
        if(T[i]==str(3,a)) count++;
    }

    //Check Vertical
    for(int i=0;i<3;i++){
        bool bi=1;
        for(int j=0;j<3;j++){
            if(T[j][i]!=a) {bi=0; break;}  
        }
        if(bi) count++;
    }

    //Check Diagonal1
    bool b1=1;
    for(int i=0;i<3;i++)
        if(T[i][i]!=a) {b1=0; break;}  
    
    if(b1) count++;

    //Check Diagonal2
    bool b2=1;
    for(int i=0;i<3;i++)
        if(T[i][2-i]!=a) {b2=0; break;}  
    
    if(b2) count++;

    return count;
}

void solve(){
   int c1=0,c2=0; //1-X  2-0
   for(int i=0;i<3;i++){
       str t;
       cin>>t;
       for(int j=0;j<3;j++){
           if(t[j]=='X') c1++;
           elif(t[j]=='0') c2++;
       }
       T.pb(t);
   }
   if(c2>c1 || c1>c2+1) {cout<<"illegal\n"; return;}

   int d1=check('X'),d2=check('0');

   if(d1>2||d2>1||(d1&&d2)) {cout<<"illegal\n"; return;}
   if(d1&&(!d2)){
       if(c1==c2) {cout<<"illegal\n"; return;}
       else {cout<<"the first player won\n"; return;}
    }
   if((!d1)&&d2){
       if(c1>c2) {cout<<"illegal\n"; return;}
       else {cout<<"the second player won\n"; return;}
   }

   if((!d1)&&(!d2)){
       if(c1+c2==9) {cout<<"draw\n"; return;}
       if(c1>c2) {cout<<"second\n"; return;}
       if(c2==c1) {cout<<"first\n"; return;}
   }
   cout<<"illegal\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}