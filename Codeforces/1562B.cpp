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

bool isprime(int a){
    bool b=true;
    for(int i=2;i<=sqrt(a);i++)
        if(!(a%i)) b=false;
    return b;
}

void solve(){
    int n,k;
    str a;
    cin>>n>>a;
    bool b=false;
    for(int i=0;i<n;i++){
        k=a[i]-'0';
        if(k==1||k==4||k==6||k==8||k==9) {
            b=true;
            break;
        }
    }
    if(b) cout<<"1\n"<<k<<'\n';
    else{
        cout<<"2\n";
        int c2=0,c3=0,c5=0,c7=0;
        b=false;
        for(int i=0;i<n;i++){
            k=a[i]-'0';
            if(k==2) c2++;
            elif(k==3) c3++;
            elif(k==5) c5++;
            elif(k==7) c7++;
            if(c2>1||c3>1||c5>1||c7>1){
                b=true;
                break;
            }
        }
        if(b) cout<<k<<k<<'\n';
        else{
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    k=(a[i]-'0')*10+(a[j]-'0');
                    b=isprime(k);
                    if(!b) break;
                }
                if(!b) break;
            }
            cout<<k<<'\n';
        }
    }
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   //Driving Code
   int t;
   cin>>t;
   while(t--) solve();
   
   return 0;
}