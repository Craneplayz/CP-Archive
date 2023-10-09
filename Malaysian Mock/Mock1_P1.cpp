#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
#define elif else if
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e9

int n = 1e9;
int C = (n - 2) / 2;

void track() {
    cout << C << endl;
    int response = 0;
    bool isTrackerRight = true, isFirst = true;
    int L = 1, R = n;
    do {
        int y;
        int mid = L + ((R - L) / 2); // 求到Segment的中心，如果有两个中位数，选择靠左的

        if (L == R) {
            y = L;
        } else if (isTrackerRight) {
            y = mid + C + 1;
        } else {
            y = mid - C;
        }
        cout << y << endl;

        cin >> response;
        if (isFirst) {
            if (response == 0) {
                isTrackerRight = true;
                R = mid;
            } else {
                isTrackerRight = false;
                L = mid + 1;
            }
            isFirst = false;
        }
        else if (isTrackerRight) {
            if (response == 0)
                R = mid;
            else
                L = mid + 1;
        } else {
            if (response == 0)
                L = mid + 1;
            else
                R = mid;
        }
    } while (response != 2); // Rabbit found
}

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        track();
    }
}