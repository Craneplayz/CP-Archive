#include <bits/stdc++.h>
using namespace std;

//Declarations
typedef deque<int> dqi;
typedef long long ll;
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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

struct Friend{
   str name;
   ll taxi=0,pizza=0,girl=0;
};

void solve(){
   int n;
   cin>>n;
   vector<Friend> Data;
   for(int i=0;i<n;i++){
      Friend F;
      int s;
      cin>>s>>F.name;
      for(int i=0;i<s;i++){
         str number;
         cin>>number;
         if(count(all(number),number[0])==6) F.taxi++;
         elif(number[0]>number[1] && number[1]>number[3] 
           && number[3]>number[4] && number[4]>number[6] && number[6]>number[7]){
            bool B=0;
            vecl C(10,0);
            for(int i=0;i<8;i++){
               if(isdigit(number[i])){
                  if(!C[number[i]-'0']) C[number[i]-'0']=1;
                  else { B=1;  break;}
               }
            }
            if(!B) F.pizza++;
         }
      }
      F.girl=s-F.taxi-F.pizza;
      Data.pb(F);
   }


   int m1=-1,m2=-1,m3=-1;
   veci C1,C2,C3;

   for(int i=0;i<n;i++){
      if(Data[i].taxi>m1){
         C1={i};
         m1=Data[i].taxi;
      }
      elif(Data[i].taxi==m1) C1.pb(i);

      if(Data[i].pizza>m2){
         C2={i};
         m2=Data[i].pizza;
      }
      elif(Data[i].pizza==m2) C2.pb(i);

      if(Data[i].girl>m3){
         C3={i};
         m3=Data[i].girl;
      }
      elif(Data[i].girl==m3) C3.pb(i);
   }

   cout<<"If you want to call a taxi, you should call: ";
   for(int i=0;i<(int)C1.sz();i++){
      cout<<Data[C1[i]].name;
      if(i==(int)C1.sz()-1) cout<<".\n";
      else cout<<", ";
   }

   cout<<"If you want to order a pizza, you should call: ";
   for(int i=0;i<(int)C2.sz();i++){
      cout<<Data[C2[i]].name;
      if(i==(int)C2.sz()-1) cout<<".\n";
      else cout<<", ";
   }

   cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
   for(int i=0;i<(int)C3.sz();i++){
      cout<<Data[C3[i]].name;
      if(i==(int)C3.sz()-1) cout<<".\n";
      else cout<<", ";
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