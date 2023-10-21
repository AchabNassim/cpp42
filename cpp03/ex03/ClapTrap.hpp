#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string		name;
        unsigned int 	hitPoints; // health
        unsigned int    energyPoints;
        unsigned int    attackDamage;

    public:

        // ************         Constructors         ************ //
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &ref);
        ClapTrap& operator=(ClapTrap &ref);
        ~ClapTrap();


        // ************         Getters & setters         ************ //

        std::string getName(void);
        int         getHitPoints(void);
        int         getEnergyPoints(void);
        int         getAttackDamage(void);

        void		setName(std::string);
        void        setHitPoints(int);
        void        setEnergyPoints(int);
        void        setAttackDamage(int);

		// Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif