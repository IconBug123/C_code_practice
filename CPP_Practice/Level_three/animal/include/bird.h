#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <utility>
#include <string>

class Bird : public Animal {
    std::string species;
    bool canTalk;
public:
    Bird(std::string s, bool t) : species(std::move(s)), canTalk(t) {}
    void speak() const override;
    std::string type() const override { return "Bird"; }
    void show()  const override;
};

#endif // BIRD_H

