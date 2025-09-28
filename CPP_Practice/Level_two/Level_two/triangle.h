#pragma once
#include "Shape.h"
#include <iostream>


class Triangle : public Shape {
	double a, b, c;
public:
	Triangle(double A, double B, double C);
	static bool valid(double A, double B, double C);


	double area() const override;
	double perimeter() const override;
	void show() const override;
	std::string name() const override;
	std::string key() const override;
	std::string serialize() const override;
};