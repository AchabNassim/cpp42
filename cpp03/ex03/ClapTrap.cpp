#include "ClapTrap.hpp"

// ************         Constructors & deconstructor      ************ //

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(10) {
    std::cout << "Default ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &ref) {
    std::cout << "ClapTrap Copy constructor called\n";
    this->name = ref.getName();
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(ClapTrap &ref) {
    std::cout << "ClapTrap Assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->name = ref.getName();
    this->hitPoints = ref.getHitPoints();
    this->energyPoints = ref.getEnergyPoints();
    this->attackDamage = ref.getAttackDamage();
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called\n";
}


// ************         Getters         ************ //

std::string	ClapTrap::getName(void) {
	return (this->name);
}

int			ClapTrap::getHitPoints(void) {
	return (this->hitPoints);
}

int			ClapTrap::getEnergyPoints(void) {
	return (this->energyPoints);
}

int			ClapTrap::getAttackDamage(void) {
	return (this->attackDamage);
}

// ************         Setters         ************ //

void		ClapTrap::setName(std::string newName) {
	this->name = newName;
}

void        ClapTrap::setHitPoints(int hitPoints) {
	this->hitPoints = hitPoints;
}

void        ClapTrap::setEnergyPoints(int energyPoints) {
	this->energyPoints = energyPoints;
}

void        ClapTrap::setAttackDamage(int attackDamage) {
	this->attackDamage = attackDamage;
}


// Methods

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " doesn't have the health to attack.\n";
    else if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " doesn't have the energy required to attack.\n";
    else {
        setEnergyPoints(this->energyPoints - 1);
        std::cout << "ClapTrap " << this->name << " Attacks " << target << ", causing " << this->attackDamage << " of damage!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= this->hitPoints) {
        setHitPoints(this->hitPoints - this->hitPoints);
    } else {
        setHitPoints(this->hitPoints - amount);
    }
    std::cout << "ClapTrap " << this->name << " has taken " << amount << " of damage! It has a remaining of " << this->hitPoints << " hit points\n";

}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " Can't heal itself, It has already been destroyed\n";
    else if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " Doesn't have the energy required repair itself.\n";
    else {
        setHitPoints(this->hitPoints + amount);
        setEnergyPoints(this->energyPoints - 1);
        std::cout << "ClapTrap " << this->name << " has repaired itself by " << amount << " hit points." << "It now has " << this->hitPoints << "hit points\n";
    }
}
