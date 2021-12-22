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

void solve(){
   str a;
   cin>>a;
   vecb2 b(201,vecb(201,0));
   int x=100,y=100;
   b[x-1][y-1]=true;
   bool c=0;
   for(int i=0;i<a.lng;i++){
       if(a[i]=='L'||a[i]=='R') {
           b[x-1][y]=true;
           b[x-1][y-1]=true;
           b[x-1][y-2]=true;
           if(a[i]=='L'){
               if(!i){
               b[x][y]=true;
               b[x][y-1]=true;
               b[x][y-2]=true;
               }
               x--;
           }
           elif(a[i]=='R') {
              if(!i){
               b[x-2][y]=true;
               b[x-2][y-1]=true;
               b[x-2][y-2]=true;
               }
               x++;
            }
       }
       elif(a[i]=='U'||a[i]=='D') {
           b[x][y-1]=true;
           b[x-1][y-1]=true;
           b[x-2][y-1]=true;
           if(a[i]=='U'){
               if(!i){
               b[x][y-2]=true;
               b[x-1][y-2]=true;
               b[x-2][y-2]=true;
               }
               y++;
           }
           elif(a[i]=='D') {
              if(!i){
               b[x][y]=true;
               b[x-1][y]=true;
               b[x-2][y]=true;
               }
               y--;
            }
        }
        if(b[x-1][y-1]){
               c=1;
               break;
           }
    }
   if(c) cout<<"BUG\n";
   else cout<<"OK\n";
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}