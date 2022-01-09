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

//Constant
#define eps 1e-9
#define Pi acos(-1)

//Debug
// #define cin fin
// #define cout fout

ifstream fin ("test.in");
ofstream fout ("test.out");

struct Mstring{
    string val;
    ll l;
    Mstring(ll a=0){
        val=to_string(a);
        l=this->val.length();
    }
    Mstring(string a){
        val=a;
        l=a.length();
    }
    Mstring operator+(Mstring A){
        Mstring C(0);
        string a=A.val,b=this->val;
        if(a.length()<b.length()) swap(a,b);
        str c="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int k1=0;
        for(int i=0;i<(int)a.length();i++){
            int q;
            if(i<(int)b.length()){
                int c1=a[i]-'0',c2=b[i]-'0';
                q=c1+c2+k1;
            }
            else{
                int c1=a[i]-'0';
                q=c1+k1;
            }

            int k2=q%10; k1=q/10;
            c+=k2+'0';
        }
        if(k1) c+='1';
        reverse(c.begin(),c.end());
        C.val=c;
        return C;
    }
    Mstring multiply(Mstring A,ll n){
        Mstring B;
        string a=A.val,b="";
        int la=a.length();
        reverse(a.begin(),a.end());

        int k1=0,k2=0;
        for(int i=0;i<la;i++){
            int c1=a[i]-'0';
            int q=(c1*n)+k1;
            k1=q/10; k2=q%10;
            b+=k2+'0';
        }
        if(k1) b+=k1+'0';
        reverse(b.begin(),b.end());
        B.val=b;
        return B;
    }

    Mstring operator*(Mstring A){
        Mstring C;
        if( A.l < this->l ) swap(A,*this);
        string b=this->val;
        reverse(b.begin(),b.end());
        
        for(int i=0;i< (this->l);i++){
            int m=b[i]-'0';
            if(m==0) continue;
            Mstring k=multiply(A,m);
            k.val+=str(i,'0');
            C+=k;
        }
        C.getlen();
        return C;
    }

    void operator+=(Mstring A){
        *this=*this+A;
    }

    void operator*=(Mstring A){
        *this=(*this)*(A);
    }

    private:
    void getlen(){
        this->l=this->val.length();
    }
};

ostream& operator<< (ostream& o,const Mstring& a){
    o << a.val;
    return o;
}

vector<Mstring> dp(1001);

Mstring fact(ll n){
    if(dp[n].val!="0") return dp[n];
    if(n<2) return dp[n]=Mstring(1);
    return dp[n]=fact(n-1)*Mstring(n);
}

void solve(){
    int n;
    while(cin>>n){
       cout<<n<<"!\n";
       cout<<fact(n)<<"\n";
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