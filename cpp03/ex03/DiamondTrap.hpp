#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>


class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
		~DiamondTrap();
		std::string	getName();
        void	    attack(std::string name);
        // using       ScavTrap::attack;
		void		setName(std::string);
		void		whoAmI();

};

#endif

