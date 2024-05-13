#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = i; j < m - i; j++)
            cout << a[i][j] << "\n";

        for (int j = i + 1; j < n - i; j++)
            cout << a[j][m - i - 1] << "\n";

        for (int j = (m - 1) - i - 1; j >= i; j--)
            cout << a[n - i - 1][j] << "\n";

        for (int j = (n - 1) - i - 1; j > i; j--)
            cout << a[j][i] << "\n";
    }
}
