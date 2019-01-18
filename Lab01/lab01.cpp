#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    long days;
    double au_km, au_mile, time;
    cin >> days;
    au_km = 39.33 * 149598000 + days * 86400 * 14.24;
    au_mile = 39.33 * 92955800 + days * 86400 * 8.85;
    time = (au_km / (299792458 / 1000 * 3600)) * 2;
    cout << au_km << endl;
    cout << au_mile << endl;
    cout << time << endl;
    return 0;
}
