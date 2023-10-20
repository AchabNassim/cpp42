#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "Default ScavTrap constructor called\n";
    this->name = "ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called\n";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap(ref.name) {
    std::cout << "ScavTrap copy constructor called\n";
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
}

ScavTrap& ScavTrap::operator=(ScavTrap &ref) {
    std::cout << "ScavTrap assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->name = getName();
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called\n";
};

void ScavTrap::attack(const std::string& target) {
    if (this->getHitPoints() <= 0)
        std::cout << "ScavTrap " << this->getName() << " doesn't have the health to attack.\n";
    else if (this->getEnergyPoints() <= 0)
        std::cout << "ScavTrap " << this->getName() << " doesn't have the energy required to attack.\n";
    else {
        setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ScavTrap " << this->getName() << " Attacks " << target << ", causing " << this->getAttackDamage() << " of damage!\n";
    }
}


void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}