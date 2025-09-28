#include "IsoscelesTrapezoid.h"
#include <cmath>
#include <string>
using namespace std;


IsoscelesTrapezoid::IsoscelesTrapezoid(double A, double B, double H) : a(A), b(B), h(H) {}
double IsoscelesTrapezoid::leg() const { return std::sqrt(h * h + (a - b) * (a - b) / 4.0); }
double IsoscelesTrapezoid::area() const { return (a + b) * 0.5 * h; }
double IsoscelesTrapezoid::perimeter() const { return a + b + 2 * leg(); }
void IsoscelesTrapezoid::show() const { cout << "IsoscelesTrapezoid(a=" << a << ", b=" << b << ", h=" << h << ")"; }
string IsoscelesTrapezoid::name() const { return "IsoscelesTrapezoid"; }
string IsoscelesTrapezoid::key() const { return string("IsoscelesTrapezoid:") + to_string(a) + "," + to_string(b) + "," + to_string(h); }
string IsoscelesTrapezoid::serialize() const { return string("IsoscelesTrapezoid,") + to_string(a) + "," + to_string(b) + "," + to_string(h); }