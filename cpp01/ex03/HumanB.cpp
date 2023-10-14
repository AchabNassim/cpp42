#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB () { 
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack() {
    if (this->weapon != NULL && !this->weapon->getType().empty())
        std::cout << this->name << " attacks with their weapon " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " Doesn't have any weapon." << std::endl;
}