#include "Zombie.hpp"

Zombie::Zombie() {
    // std::cout << "Zombie " << name << " Has been created 🧟\n";
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " Has been destroyed 🧟\n";
}

void    Zombie::announce (void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string name) {
    this->name = name;
}