#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "Default FragTrap constructor called\n";
    this->name = "FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap constructor called\n";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &ref) : ClapTrap(ref.name) {
    std::cout << "FragTrap copy constructor called\n";
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
}

FragTrap& FragTrap::operator=(FragTrap &ref) {
    std::cout << "FragTrap assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->name = getName();
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called\n";
};

void FragTrap::attack(const std::string& target) {
    if (this->getHitPoints() <= 0)
        std::cout << "FragTrap " << this->getName() << " doesn't have the health to attack.\n";
    else if (this->getEnergyPoints() <= 0)
        std::cout << "FragTrap " << this->getName() << " doesn't have the energy required to attack.\n";
    else {
        setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "FragTrap " << this->getName() << " Attacks " << target << ", causing " << this->getAttackDamage() << " of damage!\n";
    }
}

void FragTrap::highFivesGuys(void) {
    if (this->getHitPoints() <= 0)
        std::cout << "FragTrap " << this->getName() << " doesn't have the health to high five.\n";
    else if (this->getEnergyPoints() <= 0)
        std::cout << "FragTrap " << this->getName() << " doesn't have the energy required to high five.\n";
    else {
        std::cout << "FragTrap " << this->getName() << " used a high five to motivate itself and it friends (ClapTrap is schizophrenic)\n";
    }
}
