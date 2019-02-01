#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::abs;

double fn(double x) {
    double value;
    value = -6 * pow(x, 2) + 5 * x + 3;
    return value;
}

double integral(double x) {
    double value = 0;
    value = -2 * pow(x, 3) + (5.0 / 2) * pow(x, 2) + 3 * x;
    return value;
}

double trapezoid(double a, double b, long n) {
    double value = 0;
    for (double i = 0; i <= 1; i += (b - a) / n) {
        if (i == 0 or i == 1)
            value += fn(i);
        else
            value += 2 * fn(i);
    }
    return value * (b - a) / (2 * n);
}

int main() {
    double tolerance, number, integral_val, trapezoid_val;
    integral_val = integral(1);
    cin >> tolerance >> number;
    trapezoid_val = trapezoid(0, 1, number);
    
    while (abs(integral_val - trapezoid_val) > tolerance) {
        number *= 2;
        trapezoid_val = trapezoid(0, 1, number);
    }
    cout << number;
    cout << fixed << setprecision(6);
    cout << " " << trapezoid_val << " " << integral_val << " " << tolerance << endl;
}
