#include <iostream>
using namespace std;
int main() {
    int num;
    int n1, n2, n3, n4, n5;
    cout << "Enter a five-digit integer: ";
    cin >> num;
    n1 = num / 10000;
    n2 = (num % 10000) / 1000;
    n3 = (num % 1000) / 100;
    n4 = (num & 100) / 10;
    n5 = num % 10;

    if ((n1 = n5) && (n2 = n4))
        cout << "This five-digit integer is a palindrome. " << endl;
    else
        cout << "This five-digit integer is not a palindrome. " << endl;
}