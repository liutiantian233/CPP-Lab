#include "vector.h"

#include <cmath>
using std::sqrt; using std::pow;

MathVector::MathVector(long a, long b) {
    x = a;
    y = b;
}

MathVector MathVector::add(const MathVector &v) {
    return {x + v.x, y + v.y};
}

MathVector MathVector::multiply(long a) {
    return {x * a, y * a};
}

long MathVector::multiply(const MathVector &v) {
    return (x * v.x + y * v.y);
}

double MathVector::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

string vec_to_str(const MathVector &v) {
    return (std::to_string(v.x) + ":" + std::to_string(v.y));
}
