#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
		void attack(const std::string& target);
};