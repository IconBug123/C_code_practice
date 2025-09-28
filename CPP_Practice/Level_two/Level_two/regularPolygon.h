#pragma once
#include "Shape.h"
#include <iostream>


class RegularPolygon : public Shape {
	int n; // ±ßÊý
	double s; // ±ß³¤
public:
	RegularPolygon(int N, double S);
	static bool valid(int N, double S) { return N >= 3 && S > 0; }


	double area() const override;
	double perimeter() const override;
	void show() const override;
	std::string name() const override;
	std::string key() const override;
	std::string serialize() const override;
};