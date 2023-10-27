#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"


Cure::Cure() : AMateria("cure") {
    // std::cout << "Cure constructor called\n";
}

Cure::Cure(Cure &ref) {
    // std::cout << "Cure copy constructor called\n";
    this->m_type = ref.m_type;
}

Cure& Cure::operator=(Cure &ref) {
    // std::cout << "Cure assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

AMateria* Cure::clone() const {
    AMateria *ptr = new Cure();
    return (ptr);
}

Cure::~Cure() {
    // std::cout << "Cure destructor called\n";
}

void        Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << " wounds *\n"; 
}
