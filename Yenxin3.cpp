#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    constexpr int n = 10;
    int data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int num;
    cin >> num;
    int ans = find(data, data + n, num) - data;
    if (ans < n) 
        cout << ans << "\n";
    else
        cout << "Not Found\n";
}
