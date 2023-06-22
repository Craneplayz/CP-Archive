#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <list>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_set>
using namespace std;

#define ll long long
#define elif else if
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define INF 1e18

#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif

/// @brief Floating-point point
struct Point {
    /// @brief X-Coordinate
    double x;
    /// @brief Y-Coordinate
    double y;

    /// @brief Default constructor
    Point() { x = y = 0; }

    /// @brief Constructor
    /// @param _x X-Coordinate
    /// @param _y Y-Coordinate
    Point(const double _x, const double _y) : x(_x), y(_y) {}

    /// @brief Overloading < for sorting. Compares first by x-coordinate, then by y-coordinate
    /// @param other Other point
    /// @return Comparison result, true if lesser
    bool operator<(Point other) const {
        // If x-coordinate is different
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        else
            return y < other.y;
    }

    /// @brief Overloading ==
    /// @param other Other point
    /// @return TRUE if identical, FALSE if vice versa
    bool operator==(Point other) const {
        return x - other.x < EPS && y - other.y < EPS;
    }

    /// @param p1 First point
    /// @param p2 Second point
    /// @return Euclidean distance
    static double dist(const Point p1, const Point p2) {
        return hypot(p1.x - p2.x, p1.y - p2.y);
    }

    /// @param p1 First point
    /// @param p2 Second point
    /// @return Manhattan distance
    static double manhattanDist(const Point p1, const Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }

    /// @brief Rotate point p by theta degree(radian) Counter-Clockwise
    /// @param p Point
    /// @param theta Degree (radian) to rotate by
    /// @param isDeg (Optional) TRUE if by degree (default), FALSE if by radian
    /// @return New rotated point
    static Point rotate(const Point p, double theta, const bool isDeg = true) {
        if (isDeg)
            theta = theta * PI / 180.0; // Convert degree to radian
        return Point(p.x * cos(theta) - p.y * sin(theta),
                     p.x * sin(theta) + p.y * cos(theta));
    }
};

/// @brief Line in 2D Euclidean space
struct Line {
    /// @brief Coefficients - ax + by + c = 0
    /// @note b=1 for non-vertical lines; b=0 for vertical lines
    double a, b, c;

    /// @brief Constructor
    /// @param _a Coefficient of x
    /// @param _b Coefficient of y
    /// @param _c Coefficient of constant term
    Line(const double _a, const double _b, const double _c) {
        if (_b < EPS) {
            a = 1;
            b = 0;
            c = _c / _a;
        } else {
            a = _a / _b;
            b = 1;
            c = _c / _b;
        }
    }

    /// @brief Constructor from two points
    /// @param p1 First point
    /// @param p2 Second point
    Line(const Point p1, const Point p2) {
        if (fabs(p1.x - p2.x) < EPS) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1;
            c = -(double)(a * p1.x) - p1.y;
        }
    }

    /// @brief Constructor from point and gradient
    /// @param p Point
    /// @param m Gradient
    Line(const Point p, const double m) {
        if (fabs(INF - m) < EPS) {
            a = 1;
            b = 0;
            c = -p.x;
        } else {
            a = -m;
            b = 1;
            c = -(double)(a * p.x) - p.y;
        }
    }

    /// @return Get gradient of line
    double gradient() const {
        if (fabs(b) < EPS)
            return INF;
        else
            return -a;
    }

    /// @brief Overloading ==
    /// @param other Other line
    /// @return TRUE if identical
    bool operator==(Line other) const {
        return areSame(*this, other);
    }

    /// @brief Check if two lines are parallel
    /// @param l1 First line
    /// @param l2 Second line
    /// @return TRUE if two lines are parallel
    static bool areParallel(const Line l1, const Line l2) {
        return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
    }

    /// @brief Check if two lines are identical
    /// @param l1 First line
    /// @param l2 Second line
    /// @return TRUE if two lines are same
    static bool areSame(const Line l1, const Line l2) {
        return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
    }

    /// @brief Check if two lines intersects
    /// @param l1 First line
    /// @param l2 Second line
    /// @param p (Passed by reference) Returns intersection point
    /// @return TRUE if lines intersect, FALSE if lines are parallel
    static bool areIntersect(const Line l1, const Line l2, Point &p) {
        if (areParallel(l1, l2))
            return false;

        p.x = (l2.b * l1.c - l1.b * l2.c) /
              (l2.a * l1.b - l1.a * l2.b);

        if (fabs(l1.b) > EPS)
            p.y = -(l1.a * p.x + l1.c);
        else
            p.y = -(l2.a * p.x + l2.c);

        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i].x >> a[i].y;
    sort(a.rbegin(), a.rend());

    double ans = 0;
    Point p = a[0];
    for (int i = 1; i < n; i++) {
        if (p.y < a[i].y) {
            Line slope = Line(a[i], a[i - 1]);
            Line horizontal = Line(p, 0);
            Point pDown;
            Line::areIntersect(slope, horizontal, pDown);
            ans += Point::dist(a[i], pDown);
            p = a[i];
        }
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}