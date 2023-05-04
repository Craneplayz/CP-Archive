#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 56, 78, 9};

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        low = min(a[i], low);
        high = max(a[i], high);
    }
    cout << low << " " << high << "\n";
}