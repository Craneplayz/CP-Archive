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
    int Bin[3][3];
    while(cin>>Bin[0][0]>>Bin[0][1]>>Bin[0][2]){
        int sum=Bin[0][0]+Bin[0][1]+Bin[0][2];
        str ans1="ZZZ";
        for(int i=1;i<3;i++)
            for(int j=0;j<3;j++){
                cin>>Bin[i][j];
                sum+=Bin[i][j];
            }
        int ans2=sum;
        map<int,char> hash;
        hash[0]='B'; hash[1]='G'; hash[2]='C';

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++) if(i!=j)
                for(int k=0;k<3;k++) if(j!=k&&i!=k){
                    int temp=sum;
                    temp-=Bin[0][i]+Bin[1][j]+Bin[2][k];
                    if(temp<=ans2){
                        str d=""; 
                        d+=hash[i]; d+=hash[j]; d+=hash[k];
                        if(temp==ans2) ans1=min(d,ans1);
                        else ans1=d;
                        ans2=temp;
                    }
                }
        cout<<ans1<<" "<<ans2<<'\n';            
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