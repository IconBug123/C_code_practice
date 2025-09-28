#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <utility>
#include <string>

class Dog : public Animal {
    std::string name;
    int age;
public:
    Dog(std::string n, int a) : name(std::move(n)), age(a) {}
    void speak() const override;
    std::string type() const override { return "Dog"; }
    void show()  const override;
};

#endif  //DOG_H

