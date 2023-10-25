#include "../include/Cure.hpp"

Cure::Cure() : AMateria(CLASSNAME) {
    std::cout << "Default constructor called\n";
}

Cure::Cure(Cure &ref) {
    std::cout << "Cure copy constructor called\n";
    this->type = ref.type;
}

Cure& Cure::operator=(Cure &ref) {
    std::cout << "Cure assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->type = ref.type;
    return (*this);
}

AMateria* Cure::clone() const {
    AMateria *ptr = new Cure();
    return (ptr);
}
