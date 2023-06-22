#include "Geometry.hpp"
using namespace std;
using namespace Geometry;

int main() {
    Point a(100, 100), b(9, 10), c(1, 3), d;
    distToLineSegment(a, b, c, d);
    b = Point(10, 3);
    cout << d.x << " " << d.y << "\n";
}