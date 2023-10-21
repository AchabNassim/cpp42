#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap &ref);
        FragTrap& operator=(FragTrap &ref);
        ~FragTrap();
		void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif