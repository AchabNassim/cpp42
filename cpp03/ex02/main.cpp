#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap roboto("clp");
    ScavTrap robotto("scv");
    FragTrap robot("frg");
    roboto.attack("Laarbi");
    robotto.attack("Laarbi");
    robot.attack("Laarbi");
    robotto.guardGate();
    robot.highFivesGuys();
}