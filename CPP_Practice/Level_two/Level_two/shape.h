#ifndef SHAPE_HEAD
#define SHAPE_HEAD

#include <string>


class Shape {
public:
	virtual ~Shape() = default;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void show() const = 0;
	virtual std::string name() const = 0;


	// ����ȥ�غͳ־û�
	virtual std::string key() const = 0; // ����+���� Ψһ��
	virtual std::string serialize() const = 0; // �ı���ʾ���� "Circle,3.5"
};

#endif

