#include "Storage.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "IsoscelesTrapezoid.h"
#include "RegularPolygon.h"
#include "Util.h"
#include <fstream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;


static Shape* makeShapeFromLine(const std::string& line) {
	auto toks = util::splitCSV(util::trim(line));
	if (toks.empty()) return nullptr;
	const string nm = toks[0];
	try {
		if (nm == "Circle" && toks.size() == 2) {
			double r = stod(toks[1]);
			if (r > 0) return new Circle(r);
		}
		else if (nm == "Rectangle" && toks.size() == 3) {
			double w = stod(toks[1]), h = stod(toks[2]);
			if (w > 0 && h > 0) return new Rectangle(w, h);
		}
		else if (nm == "Triangle" && toks.size() == 4) {
			double a = stod(toks[1]), b = stod(toks[2]), c = stod(toks[3]);
			if (Triangle::valid(a, b, c)) return new Triangle(a, b, c);
		}
		else if (nm == "IsoscelesTrapezoid" && toks.size() == 4) {
			double a = stod(toks[1]), b = stod(toks[2]), h = stod(toks[3]);
			if (IsoscelesTrapezoid::valid(a, b, h)) return new IsoscelesTrapezoid(a, b, h);
		}
		else if (nm == "RegularPolygon" && toks.size() == 3) {
			int n = stoi(toks[1]);
			double s = stod(toks[2]);
			if (RegularPolygon::valid(n, s)) return new RegularPolygon(n, s);
		}
	}
	catch (...) {
		return nullptr;
	}
	return nullptr;
}


bool storage::saveToFile(const std::string& path, const std::vector<Shape*>& vec) {
	ofstream ofs(path);
	if (!ofs) return false;
	for (auto p : vec) ofs << p->serialize() << '\n';
	return true;
}


bool storage::loadFromFile(const std::string& path, std::vector<Shape*>& vec) {
	ifstream ifs(path);
	if (!ifs) return false;
	string line;
	while (getline(ifs, line)) {
		line = util::trim(line);
		if (line.empty()) continue;
		if (auto p = makeShapeFromLine(line)) vec.push_back(p);
	}
	return true;
}