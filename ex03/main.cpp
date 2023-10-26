#include "include/AMateria.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/ICharacter.hpp"
#include "include/Character.hpp"

int main() {
    AMateria *ice = new Ice();
    ICharacter   *rob = new Character("rob");
    rob->equip(ice);
    rob->use(0, *rob);
    delete ice;
}