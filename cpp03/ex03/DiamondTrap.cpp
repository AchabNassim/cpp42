#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ios>

DiamondTrap::DiamondTrap() {
    std::cout << "Default DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    std::cout << "DiamondTrap constructor called\n";
    this->ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap &ref) : ClapTrap(), FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap constructor called\n";
    this->name = ref.name;
    this->hitPoints = ref.hitPoints;
    this->energyPoints = ref.energyPoints;
    this->attackDamage = ref.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &ref) {
    if (this == &ref)
        return (*this);
    std::cout << "DiamondTrap assignement operator called\n";
    this->name = ref.name;
    this->hitPoints = ref.hitPoints;
    this->energyPoints = ref.energyPoints;
    this->attackDamage = ref.attackDamage;
    return (*this);
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
    std::cout << "Who the hell am I? well, I'm named " << getName() << " and my Parent's name is " << ClapTrap::getName() << std::endl;
}
