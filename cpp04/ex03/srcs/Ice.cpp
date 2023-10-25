#include "../include/Ice.hpp"

Ice::Ice() : AMateria(CLASSNAME) {
    std::cout << "Default constructor called\n";
}

Ice::Ice(Ice &ref) {
    std::cout << "Ice copy constructor called\n";
    this->type = ref.type;
}

Ice& Ice::operator=(Ice &ref) {
    std::cout << "Ice assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->type = ref.type;
    return (*this);
}

AMateria* Ice::clone() const {
    AMateria *ptr = new Ice();
    return (ptr);
}
