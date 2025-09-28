#include "Cat.h"
#include <iostream>

void Cat::speak() const {
    std::cout << "Cat " << name << " says: Meow~\n";
}
void Cat::show() const {
    std::cout << "Cat{name=" << name << ", color=" << color << "}";
}
