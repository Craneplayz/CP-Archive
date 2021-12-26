#include <iostream>
using namespace std;

//Declarations
#define ll long long
#define veci vector<int>

//Functions
#define pb push_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve(){
   int n,k,sum=0,c=0,d;
   cin>>n>>k;
   k=240-k;
   for(int i=1;i<=n;i++){
       //cout<<i<<" "<<n<<" "<<sum<<" "<<k<<endl;
       sum+=i*5;
       if(sum>k) {
           c++;
           d=i-1;
           break;
        }
   }

   if(c) cout<<d<<endl;
   else cout<<n<<endl;
}

int main(){
   //Fast Input
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   //Driving Code
   solve();
    
   return 0;
}