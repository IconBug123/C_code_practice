#include "Rectangle.h"
#include <string>
using namespace std;


Rectangle::Rectangle(double W, double H) : w(W), h(H) {}
double Rectangle::area() const { return w * h; }
double Rectangle::perimeter() const { return 2 * (w + h); }
void Rectangle::show() const { cout << "Rectangle(w=" << w << ", h=" << h << ")"; }
string Rectangle::name() const { return "Rectangle"; }
string Rectangle::key() const { return string("Rectangle:") + to_string(w) + "," + to_string(h); }
string Rectangle::serialize() const { return string("Rectangle,") + to_string(w) + "," + to_string(h); }