#include "Dog.h"
#include <iostream>

void Dog::speak() const {
    std::cout << "Dog " << name << " says: Woof!\n";
}
void Dog::show() const {
    std::cout << "Dog { name=" << name << ", age=" << age << " }";
}
