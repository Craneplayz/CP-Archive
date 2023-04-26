#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string t;
        getline(cin, t);

        while (!isdigit(t.front())) {
            t.erase(t.begin());
        }

        for (int i = 0; i < (int)t.length(); i++) {
            if (t[i] == ' ' &&
                ((i && isalnum(t[i - 1])) ||
                 (i < (int)t.length() && isalnum(t[i + 1]))))
                t[i] = '-';
            else
                t.erase(t.begin() + i--);
        }

        cout << t << '\n';
    }
}