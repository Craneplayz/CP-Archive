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

#define EPS 1e-9
#define INF 1e18
#define PI acos(-1)

namespace Geometry {
    template <typename T>
    struct PointInt;
    struct Point;
    struct Line;
    struct Vec;

    /// @brief Integer point
    template <typename T>
    struct PointInt {
        /// @brief X-Coordinate
        T x;
        /// @brief Y-Coordinate
        T y;

        /// @brief Default constructor
        PointInt() : x(0), y(0) {}

        /// @brief Constructor
        /// @param _x X-Coordinate
        /// @param _y Y-Coordinate
        PointInt(const T _x, const T _y) : x(_x), y(_y) {}

        /// @brief Overloading < for sorting. Compares first by x-coordinate, then by y-coordinate
        /// @param other Other point
        /// @return TRUE if lesser
        bool operator<(PointInt other) const {
            // If x-coordinate is different
            if (x != other.x)
                return x < other.x;
            else
                return y < other.y;
        }

        /// @brief Overloading ==
        /// @param other Other point
        /// @return TRUE if identical, FALSE if vice versa
        bool operator==(PointInt other) const {
            return x == other.x && y == other.y;
        }

        /// @brief Overloading !=
        /// @param other Other point
        /// @return TRUE if not identical, FALSE if identical
        bool operator!=(PointInt other) const {
            return !operator==(*this, other);
        }

        bool operator<=(PointInt other) const {
            return operator<(*this, other) || operator==(*this, other);
        }

        bool operator>(PointInt other) const {
            return !operator>(*this, other);
        }

        bool operator>=(PointInt other) const {
            return operator>(*this, other) || operator==(*this, other);
        }

        /// @param p1 First point
        /// @param p2 Second Point
        /// @return Euclidean distance
        static double dist(const PointInt p1, const PointInt p2) {
            return hypot(p1.x - p2.x, p1.y - p2.y);
        }

        /// @param p1 First point
        /// @param p2 Second point
        /// @return Manhattan distance
        static T manhattanDist(const PointInt p1, const PointInt p2) {
            return abs(p1.x - p2.x) + abs(p1.y - p2.y);
        }
    };

    /// @brief Floating-point point
    struct Point {
        /// @brief X-Coordinate
        double x;
        /// @brief Y-Coordinate
        double y;

        /// @brief Default constructor
        Point() : x(0), y(0) {}

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

        /// @brief Generate line from two points
        /// @param p1 First point
        /// @param p2 Second point
        /// @param l (Passed by reference) Result line
        template <typename T>
        static void pointsToLine(PointInt<T> p1, PointInt<T> p2, Line &l) {
            if (fabs(p1.x - p2.x) < EPS) {
                l.a = 1;
                l.b = 0;
                l.c = -p1.x;
            } else {
                l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
                l.b = 1;
                l.c = -(double)(l.a * p1.x) - p1.y;
            }
        }

        /// @brief Overloading ==
        /// @param other Other line
        /// @return TRUE if identical
        bool operator==(Line other) const {
            return areSame(*this, other);
        }

        friend ostream &operator<<(ostream &os, Line &l) {
            if (l.b < EPS)
                os << "-";
            if (fabs(l.a - 1) > EPS)
                os << fabs(l.a);
            if (fabs(l.a) > EPS)
                os << "x ";

            if (fabs(l.b) > EPS) {
                if (l.b < EPS)
                    os << "- ";
                else
                    os << "+ ";
                os << fabs(l.b) << "y ";
            }

            if (l.c < EPS)
                os << "- ";
            else
                os << "+ ";
            os << fabs(l.c) << " ";

            os << "= 0";

            return os;
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

    struct Vec {
        /// @brief X-Magnitude
        double x;
        /// @brief Y-Magnitude
        double y;

        /// @brief Default constructor
        Vec() : x(0), y(0) {}

        /// @brief Constructor
        /// @param _x X-Magnitude
        /// @param _y Y-Magnitude
        Vec(double _x, double _y) : x(_x), y(_y) {}

        /// @brief Constructor
        /// @param p1 Starting point
        /// @param p2 Ending point
        Vec(const Point p1, const Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}

        /// @brief Scale vector by scaling factor
        /// @param v Vector
        /// @param s Scaling factor
        /// @return Scaled vector
        static Vec scale(const Vec v, const double s) {
            return Vec(v.x * s, v.y * s);
        }

        /// @brief Overloading *= for scaling vector
        /// @param s Scaling Factor
        Vec &operator*=(const double s) {
            return *this = scale(*this, s);
        }

        /// @brief Overloading * for scaling vector
        /// @param vec Vector
        /// @param s Scaling Factor
        /// @return Scaled vector
        friend Vec operator*(Vec vec, const double s) {
            return vec *= s;
        }

        /// @brief Overloading * for scaling vector
        /// @param s Scaling Factor
        /// @param vec Vector
        /// @return Scaled vector
        friend Vec operator*(const double s, Vec vec) {
            return vec *= s;
        }

        /// @brief Translate point by vector
        /// @param p Point
        /// @param v Translation vector
        /// @return Translated point
        static Point translate(const Point p, const Vec v) {
            return Point(p.x + v.x, p.y + v.y);
        }

        /// @param a First vector
        /// @param b Second vector
        /// @return Dot product
        static double dot(const Vec a, const Vec b) {
            return a.x * b.x + a.y * b.y;
        }

        /// @brief Overload * for dot product
        /// @param a First vector
        /// @param b Second vector
        /// @return Dot product
        friend double operator*(const Vec a, const Vec b) {
            return dot(a, b);
        }

        /// @param a First vector
        /// @param b Second vector
        /// @return Cross product
        static double cross(const Vec &a, const Vec &b) {
            return a.x * b.y - a.y * b.x;
        }

        /// @brief Overloading ^ for cross product
        /// @return Cross product
        double operator^(const Vec &b) const {
            return cross(*this, b);
        }

        /// @return Norm of vector squared, better precision
        double normSquared() const {
            return x * x + y * y;
        }

        /// @return Norm of vector ≈ Length
        double norm() const {
            return sqrt(this->normSquared());
        }

        /// @param a First vector
        /// @param b Second vector
        /// @param isDeg (Optional) FALSE for radian by default, TRUE for degree
        /// @return Angle between two vectors in radian/degree
        static double angle(const Vec &a, const Vec &b, const bool isDeg = false) {
            double rad = acos(a * b / sqrt(a.normSquared() * b.normSquared()));
            if (isDeg)
                return rad / PI * 180;
            else
                return rad;
        }
    };

    Point &operator+=(Point &p, const Vec &vec) {
        return p = Vec::translate(p, vec);
    }

    Point operator+(Point p, const Vec &vec) {
        return p += vec;
    }

    /// @brief Overloading + for point translation by vector
    /// @param vec Vector
    /// @param p Point
    /// @return Translate
    Point operator+(const Vec &vec, Point p) {
        return p += vec;
    }

    /// @brief Distance of point to the line denoted by two points
    /// @param p Point of interest
    /// @param a First point determining the line
    /// @param b Second point determining the line
    /// @param c (Passed by referenced) Closest point on line ab to point p
    /// @return Result distance; If a and b are the same, return distance between a and p
    double distToLine(Point p, Point a, Point b, Point &c) {
        // Ill-defined: a, b are the same
        if (a == b)
            return Point::dist(a, p);

        Vec ap = Vec(a, p), ab = Vec(a, b);

        // ap投影到ab向量方向的长度是|ap|cos(θ)，用点积除以|ab|一次可以求得这个值
        // 将此值再乘上ab的单位向量 = ab/|ab|，可以拿到以向量ab方向，长度为向量ap投影的新向量 ac
        // 由于计算向量的范数|ab|会调用到根号，影响Precision，所以将两次除法合并成模数的平方normSquared，先行计算
        // 将点a沿此向量平移，可得过点p的线ab的垂线的垂足c

        double u = (ap * ab) / ab.normSquared();
        c = a + u * ab;

        return Point::dist(c, p);
    }

    /// @brief Distance of point to the line segment denoted by two points
    /// @param p Point of interest
    /// @param a First point determining the line segment
    /// @param b Second point determining the line segment
    /// @param c (Passed by reference) Closest point on line segment ab to point p
    /// @return Result distance
    double distToLineSegment(Point p, Point a, Point b, Point &c) {
        Vec ap = Vec(a, p), ab = Vec(a, b);
        // u = [0, 1] 代表着线段ab的范围，超过了就代表离p最近的点c需要平移出线段
        double u = (ap * ab) / ab.normSquared();

        if (u < 0.0) {
            // Point p is closer to point a
            // 假设今天是直线，那么点c要往a的方向平移出去才能垂直，可见点a离点c更加接近
            c = a;
            return Point::dist(p, c);
        } else if (u > 1.0) {
            // Point p is closer to point b
            // 假设今天是直线，那么点c要往b的方向平移出去才能垂直，可见点b离点c更加接近
            c = a;
            return Point::dist(p, c);
        } else {
            // 点c在线段ab之内，可以视作和当ab是直线时为一样情境
            return distToLine(p, a, b, c);
        }
    }

    bool ccw(const Vec& a, const Vec& b) {
        return (a ^ b) >= 0;
    }

    /// @brief Counter-clockwise test via taking in three points denoting two vectors
    /// @param p Starting point of both vector
    /// @param a Ending point of vector A
    /// @param b Ending point of vector B
    /// @return TRUE if vector B is at the counter-clockwise of vector A,
    ///         or when three points are collinear
    bool ccw(const Point& p, const Point& a, const Point& b) {
        return ccw(Vec(p, a), Vec(p, b));
    }

    /// @brief Test if two vectors are collinear via taking in three points denoting them
    /// @param p Starting point of both vector
    /// @param a Ending point of vector A
    /// @param b Ending point of vector B
    /// @return TRUE if three points are collinear
    bool areCollinear(Point p, Point a, Point b) {
        return (Vec(p, a) ^ Vec(p, b)) == 0;
    }

    struct Circle {
        /// @brief Centre of circle
        Point O;
        /// @brief Radius of circle
        double r;

        /// @return Diameter of circle
        double diameter() const {
            return 2 * r;
        }

        /// @return Area of circle
        double area() const {
            return PI * r * r;
        }

        /// @brief Check if integer point is inside circle
        /// @tparam T Integral type
        /// @param p Point of interest
        /// @param O Centre of circle
        /// @param r Radius of circle
        /// @return 0 if outside circle; 1 if inside circle; 2 if on border of the circle
        template <typename T>
        static int insideCircle(const PointInt<T> &p, const PointInt<T> &O, const T r) {
            T dx = p.x - O.x, dy = p.y - O.y;
            // 比较平方后的，对正数来说，平方不会改变不等式关系，避免Floating-point Number
            T pO = dx * dx + dy * dy, rSquare = r * r;
            if (dx > pO)
                return 0;
            else if (dx < pO)
                return 1;
            else if (dx == pO)
                return 2;
        }

        /// @brief Check if point is inside circle
        /// @param p Point of interest
        /// @param O Centre of circle
        /// @param r Radius of circle
        /// @return 0 if outside circle; 1 if inside circle; 2 if on border of the circle
        static int insideCircle(const Point &p, const Point &O, const double r) {
            double dx = p.x - O.x, dy = p.y - O.y;
            // 比较平方后的，对正数来说，平方不会改变不等式关系，避免平方根的Precision问题
            double pO = dx * dx + dy * dy, rSquare = r * r;
            if (dx > pO)
                return 0;
            else if (dx < pO)
                return 1;
            else if (abs(dx - pO) > EPS)
                return 2;
        }

        /// @brief Check if point is inside circle
        /// @note Member function
        /// @param P Point of interest
        /// @return 0 if outside circle; 1 if inside circle; 2 if on border of the circle
        int insideCircle(const Point &p) const {
            return insideCircle(p, this->O, this->r);
        }
    };

    /// @brief Polygon
    /// @note std::vector<Points>, stored counter-clockwise
    struct Polygon : public vector<Point> {
        /// @brief Check if point is inside polygon
        /// @param p Point of interest
        /// @return TRUE if point is inside polygon, FALSE if not
        bool insidePolygon(const Point &p) const {
            double sum = 0;
            for (int i = 0; i < (int)this->size() - 1; i++) {
                Vec pa(p, (*this)[i]), pb(p, (*this)[i + 1]);
                // Counter-clockwise Test
                if (ccw(pa, pb))
                    sum += Vec::angle(pa, pb); // Add if left turn
                else
                    sum -= Vec::angle(pa, pb); // Subtract if right turn

                // 凹多边形可以理解成先多走了，再Compensate回来多走的那些Angle
            }
            // Sum of angle will be 2π if the point's inside polygon
            return fabs(sum - 2 * PI) < EPS;
        }
    };

    namespace ConvexHull{
        Polygon grahamScan(vector<Point>& points) {

        }
    }
}
