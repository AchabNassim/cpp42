#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <ios>

DiamondTrap::DiamondTrap() {
    std::cout << "Default DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "DiamondTrap constructor called\n";
    this->ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Diamond destructor called\n";
}

void	DiamondTrap::attack(std::string name) {
    ScavTrap::attack(name);
}

std::string DiamondTrap::getName() {
    return (this->name);
}

void    DiamondTrap::setName(std::string newName) {
    this->name = newName;
}

void    DiamondTrap::whoAmI() {
    std::cout << "Who the hell am I? well, I'm named " << getName() << " and my Parent is named " << ClapTrap::getName() << std::endl;
}
