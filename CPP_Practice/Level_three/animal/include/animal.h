#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
    virtual std::string type() const = 0;   // 返回类型名
    virtual void show()  const = 0;         // 展示属性
};

#endif // ANIMAL_H

