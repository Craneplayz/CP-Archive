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

ofstream fout ("test.out");
ifstream fin ("test.in");

struct Pole{
    ll x,y,h;
};

bool operator<(Pole a,Pole b){
    return abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y);
}

void solve(){
    int n,CASE=0;
    while(cin>>n){
        if(!n) break;
        cout<<"Data set "<<++CASE<<":\n";
        map<double,ll> hash;
        vector<vector<Pole>> dat;
        ll i_hash=0;
        for(ll i=0;i<n;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            double m;
            if(x) m=abs((double)y/x);
            else m=5000000;
            if(x<0&&y>=0) m+=1000000;
            elif(x>=0&&y<0) m+=2000000;
            elif(x<0&&y<0) m+=3000000;
            if(hash.find(m)==hash.end()){
                hash[m]=i_hash++;
                dat.pb(vector<Pole>());
            } 
            dat[hash[m]].pb(Pole{x,y,z});
        }
        bool bo=1;
        vecpl rec;
        for(ll i=0;i<dat.sz();i++){
            sort(dat[i].begin(),dat[i].end());
            ll mi=-1;
            for(int j=0;j<dat[i].sz();j++){
                if(dat[i][j].h<=mi){
                    bo=0;
                    rec.pb({dat[i][j].x,dat[i][j].y});
                }
                mi=max(dat[i][j].h,mi);
            }
        }
        sort(rec.begin(),rec.end());
        if(bo) cout<<"All the lights are visible.\n";
        else{
            cout<<"Some lights are not visible:\n";
            for(int i=0;i<rec.sz();i++){
                cout<<"x = "<<rec[i].first<<", y = "<<rec[i].second;
                if(i!=rec.sz()-1) cout<<";";
                else cout<<".";
                cout<<"\n";
            }

        }
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