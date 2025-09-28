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


	// 用于去重和持久化
	virtual std::string key() const = 0; // 类型+参数 唯一键
	virtual std::string serialize() const = 0; // 文本表示，如 "Circle,3.5"
};

#endif

