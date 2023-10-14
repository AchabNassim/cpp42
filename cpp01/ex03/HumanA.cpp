#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

HumanA::~HumanA() {
}

void    HumanA::attack() {
    if (!this->weapon.getType().empty())
        std::cout << this->name << " attacks with their weapon " << weapon.getType() << std::endl;
    else
        std::cout << this->name << " Doesn't have any weapon." << std::endl;
}