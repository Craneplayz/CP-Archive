#include <iostream>
#include <cmath>
using namespace std;
 
#define pb push_back
#define pi acos(-1)
 
int main(){
    long long n,m;
    cin>>n>>m;
    double h=sqrt(3)/2;
    cout<<max(((long long)(n/h))*(2*m-1),((long long)(m/h))*(2*n-1))<<'\n';
}