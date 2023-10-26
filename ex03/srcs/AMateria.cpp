#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria() {
    std::cout << "Default constructor called\n";
}

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria constructor called\n";
    this->m_type = type;
}

AMateria::AMateria(AMateria &ref) {
    std::cout << "AMateria copy constructor called\n";
    this->m_type = ref.m_type;
}

AMateria& AMateria::operator=(AMateria &ref) {
    std::cout << "AMateria assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called\n";
}

const std::string& AMateria::getType() const {
    return (this->m_type);
}

void        AMateria::use(ICharacter &target) {
    std::cout << this->m_type << " is used on " << target.getName() << "\n"; 
}