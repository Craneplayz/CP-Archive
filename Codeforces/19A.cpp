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

struct team{
    str name;
    int goal;
    int miss;
    int score;
    int d;
    team(){
        goal=0;
        miss=0;
        score=0;
        d=0;
    }
    void diff(){
        d=goal-miss;
    }
};

bool operator< (team a, team b){
    if(a.score>b.score) return true;
    elif(a.score<b.score) return false;
    else{
        if(a.d>b.d) return 1;
        elif(a.d<b.d) return 0;
        else{
            if(a.goal>=b.goal) return 1;
            elif(a.goal<b.goal) return 0;
        }
    }
}

void solve(){
   int n;
   cin>>n;
   int n1=n*(n-1)/2,n2=n/2;
   msi m;
   team t0;
   vector<team> a(n,t0);
   for(int i=0;i<n;i++){
       str t;
       cin>>t;
       m.insert({t,i});
       a[i].name=t;
   }
   for(int i=0;i<n1;i++){
       str t1,t2="";
       cin>>t1; //A-B
       int j=0;
       for(int i=0;i<t1.lng;i++){
           if(t1[i]=='-') {
               j=i+1;
               break;
           }
           else t2+=t1[i];
       }
       t1.erase(0,j);
       int k1=m[t2],k2=m[t1];
       j=0;
       cin>>t1;
       t2.clear();
       for(int i=0;i<t1.lng;i++){
           if(t1[i]==':') {
               j=i+1;
               break;
           }
           else t2+=t1[i];
       }
       t1.erase(0,j);
       int k3=stoi(t2),k4=stoi(t1);
        a[k1].goal+=k3;
        a[k1].miss+=k4;
        a[k2].goal+=k4;
        a[k2].miss+=k3;
        if(k3>k4) a[k1].score+=3;
        elif(k3<k4) a[k2].score+=3;
        else{
            a[k1].score++;
            a[k2].score++;
        }
    }
    for(int i=0;i<n;i++) a[i].diff();
    sort(a.begin(),a.end());
    vecs c;
    for(int i=0;i<n2;i++)
        c.pb(a[i].name);
    sort(c.begin(),c.end());
    for(str i:c) cout<<i<<'\n';
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}