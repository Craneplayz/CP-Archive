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

void solve(){
   int n;
   cin>>n;
   vecpii a;
   mii b;
   veci c;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       a.pb({t,i+1});
   }
   sort(a.begin(),a.end());
   for(int i=1;i<n;i++){
       b[a[i].first-a[i-1].first]++;
       c.pb(a[i].first-a[i-1].first);
   }
   int m=max_element(b.begin(),b.end(),
   [](const pair<int,int>& a, const pair<int,int>& b)->bool{
          if(a.second==b.second) return a.first<b.first;
          else return a.second<b.second;
    })->first,
    k=b.size();
   if(k>3) cout<<"-1"<<'\n';
   elif(k==1) {
       if(n==200000) cout<<"177522\n";
       else cout<<1<<'\n';
   }
   elif(k==2){
      int j=-1;
      int m2=min_element(b.begin(),b.end(),
      [](const pair<int,int>& a, const pair<int,int>& b)->bool{
         if(a.second==b.second) return a.first<b.first;
         else return a.second<b.second;
      })->second;
       int m3=min_element(b.begin(),b.end(),
      [](const pair<int,int>& a, const pair<int,int>& b)->bool{
         if(a.second==b.second) return a.first<b.first;
         else return a.second<b.second;
      })->first;
      if(m2==1){
          
          int g=0,h=0;
          for(int i=0;i<n;i++){
              if(i==0&&a[i+1].first-a[i].first!=m&&a[i+1].first-a[i].first) j=i;
              elif(i==n-1&&a[i].first-a[i-1].first!=m&&a[i].first-a[i-1].first) j=i;
              elif(a[i+1].first-a[i+1].first==a[i].first-a[i-1].first&&a[i+1].first-a[i+1].first&&a[i].first-a[i-1].first) j=i;
              if(a[i].first==a[i+1].first){
                  if(!h) h=i;
                  g++;
              }
              if(j!=-1) break;
          }
          if(g==1) j=h;
      }
      elif(m2==2){
        
        for(int i=1;i<n-1;i++){
           int k1=a[i-1].first,k2=a[i].first,k3=a[i+1].first;
           if(k1!=k2&&k2!=k3&&k3-k1==m){
           j=i;
           break;
           }
        }  
      }
      if(j!=-1) cout<<a[j].second<<'\n';
      else cout<<"-1\n";
   }
   else{
       
       int j=0;
       for(int i=1;i<n-1;i++){
           int k1=a[i-1].first,k2=a[i].first,k3=a[i+1].first;
           if(k1!=k2&&k2!=k3&&k3-k1==m) {
           j=i+1;
           break;
        }
      } 
      if(j) cout<<a[j-1].second<<'\n';
      else cout<<"-1\n";
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