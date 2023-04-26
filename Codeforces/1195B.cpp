#include <iostream>
using namespace std;

int main(){
    long long n, k; // n: number of moves, k: number of candies left
    cin >> n >> k;

    long long candiesEaten = 0;
    long long L = 1, R = n;
    while (L <= R){
        long long mid = L + ((R - L + 1) >> 1);

        long long candiesPut = (mid * (mid + 1)) >> 1;
        candiesEaten = n - mid;

        if (candiesPut -  candiesEaten == k)
            break;
        else if (candiesPut -  candiesEaten > k)
            R = mid - 1;
        else
            L = mid + 1;
    }

    cout << candiesEaten << "\n";
}