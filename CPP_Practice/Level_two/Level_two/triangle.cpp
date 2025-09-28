#include "Triangle.h"
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

Triangle::Triangle(double A, double B, double C) : a(A), b(B), c(C) {}
bool Triangle::valid(double A, double B, double C) {
	return A > 0 && B > 0 && C > 0 && A + B > C && A + C > B && B + C > A;
}


double Triangle::area() const {
	double s = (a + b + c) / 2.0;
	return sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
}


double Triangle::perimeter() const { return a + b + c; }
void Triangle::show() const { cout << "Triangle(a=" << a << ", b=" << b << ", c=" << c << ")"; }
string Triangle::name() const { return "Triangle"; }
string Triangle::key() const { return string("Triangle:") + to_string(a) + "," + to_string(b) + "," + to_string(c); }
string Triangle::serialize() const { return string("Triangle,") + to_string(a) + "," + to_string(b) + "," + to_string(c); }