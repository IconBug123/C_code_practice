#pragma once
#include "Shape.h"
#include <iostream>


class IsoscelesTrapezoid : public Shape {
	double a, b, h; // ���µ� a,b ��� h
public:
	IsoscelesTrapezoid(double A, double B, double H);
	static bool valid(double A, double B, double H) { return A > 0 && B > 0 && H > 0; }


	double leg() const; // ����
	double area() const override;
	double perimeter() const override;
	void show() const override;
	std::string name() const override;
	std::string key() const override;
	std::string serialize() const override;
};