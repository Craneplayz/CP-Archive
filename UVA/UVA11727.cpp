#include<bits/stdc++.h>

int main(){
    int t;
    std::cin>>t;
    for(int i=1;i<=t;i++){
        int arr[3];
        std::cin>>arr[0]>>arr[1]>>arr[2];
        std::sort(arr,arr+3);
        std::cout<<"Case "<<i<<": "<<arr[1]<<"\n";
    }
    return 0;
}