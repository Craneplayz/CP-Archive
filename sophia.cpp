#include <iostream>
#include <string>
using namespace std;

// C++初始模板程序
bool isPalindrome(int n);

int main() {
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--)
        if (isPalindrome(i) == 1) {
            cout << i << endl;
            break;
        }

    return 0;
}

bool isPalindrome(int n) {
    string s = to_string(n);
    int l = s.size();

    for (int i = 0; i < (l + 1) / 2; i++)
        if (s[i] != s[l - 1 - i])
            return false;

    return true;
}