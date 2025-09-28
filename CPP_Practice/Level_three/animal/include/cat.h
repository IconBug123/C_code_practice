#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <utility>
#include <string>

class Cat : public Animal {
    std::string name;
    std::string color;
public:
    Cat(std::string n, std::string c) : name(std::move(n)), color(std::move(c)) {}
    void speak() const override;
    std::string type() const override { return "Cat"; }
    void show()  const override;
};

#endif // CAT_H

