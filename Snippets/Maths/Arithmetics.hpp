#include <cmath>

#define double long double

double Quadratic(long long a, long long b, long long c){
    
    double delta = b * b - 4. * a * c;

    return (- b + sqrt(delta)) / (2 * a);
}

double Citardauq(double a, double b, double c){
    double delta = b * b - 4 * a * c;

    return (2 * c) / (-b - sqrt(delta));
}