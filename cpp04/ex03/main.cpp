#include "include/AMateria.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/ICharacter.hpp"
#include "include/Character.hpp"

int main() {
    AMateria    *ice = new Ice();
    ICharacter  *rob = new Character("rob");
    rob->equip(ice);
    rob->equip(new Ice());
    rob->equip(new Ice());
    rob->equip(new Cure());
    rob->equip(new Ice());
    
    rob->use(3, *rob);
    delete ice;
}