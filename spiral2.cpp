#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<bool>> b(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int k = 0;

    auto walk = [&a, &b, &k, &n, &m](const int u, const int v) {
        if (!(0 <= u && u < n && 0 <= v && v < m))
            return true;

        if (!b[u][v]) {
            cout << a[u][v] << "\n";
            b[u][v] = true;
            k++;
            return false;
        }
        return true;
    };

    pair<int, int> uv = {0, 0};

    while (true) {
        int u = uv.first, v = uv.second;

        while (true) {
            bool res = walk(u, v);
            if (res || v == m - 1) {
                if (res)
                    v--;
                u++;
                break;
            } else
                v++;
        }

        while (true) {
            bool res = walk(u, v);
            if (res || u == n - 1) {
                if (res)
                    u--;
                v--;
                break;
            } else
                u++;
        }

        while (true) {
            bool res = walk(u, v);
            if (res || v == 0) {
                if (res)
                    v++;
                u--;
                break;
            } else
                v--;
        }

        while (true) {
            bool res = walk(u, v);
            if (res || u == 0) {
                if (res)
                    u++;
                v++;
                break;
            } else
                u--;
        }

        if (k == n * m)
            break;
        else
            uv = pair<int, int>{u, v};
    }

    return 0;
}