#pragma once
#include "Shape.h"
#include <iostream>


class Rectangle : public Shape {
	double w, h;
public:
	Rectangle(double W, double H);
	double area() const override;
	double perimeter() const override;
	void show() const override;
	std::string name() const override;
	std::string key() const override;
	std::string serialize() const override;
};
