#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    // std::cout << "Zombie " << name << " Has been created 🧟\n";
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " Has been destroyed 🧟\n";
}

void    Zombie::announce (void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}