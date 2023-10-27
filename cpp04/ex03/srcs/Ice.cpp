#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"


Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice constructor called\n";
}

Ice::Ice(Ice &ref) {
    // std::cout << "Ice copy constructor called\n";
    this->m_type = ref.m_type;
}

Ice& Ice::operator=(Ice &ref) {
    // std::cout << "Ice assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

AMateria* Ice::clone() const {
    AMateria *ptr = new Ice();
    return (ptr);
}

Ice::~Ice() {
    // std::cout << "Ice destructor called\n";
}

void        Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n"; 
}