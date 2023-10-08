#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    Weapon->setType(type);
}

Weapon::~Weapon() {
    std::cout << Weapon.getType << " Has been destroyed\n";
}

const std::string& Weapon::getType(void) {
    return (this->type);
}

void    setType(std::string newType) {
    this->type = newType;
}
