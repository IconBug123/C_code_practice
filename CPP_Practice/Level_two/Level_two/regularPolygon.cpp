#include "RegularPolygon.h"
#include "Util.h"
#include <cmath>
#include <string>
using namespace std;


RegularPolygon::RegularPolygon(int N, double S) : n(N), s(S) {}
double RegularPolygon::area() const { return n * s * s / (4.0 * std::tan(util::pi() / n)); }
double RegularPolygon::perimeter() const { return n * s; }
void RegularPolygon::show() const { cout << "RegularPolygon(n=" << n << ", s=" << s << ")"; }
string RegularPolygon::name() const { return "RegularPolygon"; }
string RegularPolygon::key() const { return string("RegularPolygon:") + to_string(n) + "," + to_string(s); }
string RegularPolygon::serialize() const { return string("RegularPolygon,") + to_string(n) + "," + to_string(s); }