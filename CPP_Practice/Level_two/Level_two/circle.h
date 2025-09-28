#pragma once
#include "Shape.h"
#include <iostream>


class Circle : public Shape {
	double r;
public:
	explicit Circle(double radius);
	double area() const override;
	double perimeter() const override;
	void show() const override;
	std::string name() const override;
	std::string key() const override;
	std::string serialize() const override;
};
