#include "Bird.h"
#include <iostream>

void Bird::speak() const {
    if (canTalk) std::cout << species << " parrot says: Hello!\n";
    else         std::cout << species << " bird chirps: Tweet!\n";
}
void Bird::show() const {
    std::cout << "Bird{species=" << species
        << ", canTalk=" << (canTalk ? "true" : "false") << "}";
}
