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
typedef vector<pair<long long,long long>> vecpll;
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

ofstream fout ("test.out");
ifstream fin ("test.in");

void solve(){
    str a;
    priority_queue<pii,vecpii,greater<pii>> pq;
    int Q[3001];
    while(cin>>a){
        if(a=="#") break;
        int Q_num,time;
        cin>>Q_num>>time;
        Q[Q_num]=time;
        pq.push({time,Q_num});
    }
    int n;
    cin>>n;
    while(n--){
        pii front=pq.top();
        cout<<front.second<<'\n';
        pq.pop();
        front.first+=Q[front.second];
        pq.push(front);
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
