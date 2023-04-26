#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    bool b = true;
    int i = 0, j = s.length() - 1;
    while (i < j && b) {
        b = (s[i] == s[j]);
        i++;
        j--;
    }
    return b;
}
