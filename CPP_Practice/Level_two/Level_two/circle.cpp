#include "Circle.h"
#include "Util.h"
using namespace std;

Circle::Circle(double radius) : r(radius) {}
double Circle::area() const { return util::pi() * r * r; }
double Circle::perimeter() const { return 2 * util::pi() * r; }
void Circle::show() const { cout << "Circle(r=" << r << ")"; }
string Circle::name() const { return "Circle"; }
string Circle::key() const { return string("Circle:") + to_string(r); }
string Circle::serialize() const { return string("Circle,") + to_string(r); }

