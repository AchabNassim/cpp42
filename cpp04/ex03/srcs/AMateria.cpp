#include "../include/AMateria.hpp"

AMateria::AMateria() {
    std::cout << "Default constructor called\n";
}

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria constructor called\n";
    this->type = type;
}

AMateria::AMateria(AMateria &ref) {
    std::cout << "AMateria copy constructor called\n";
    this->type = ref.type;
}

AMateria& AMateria::operator=(AMateria &ref) {
    std::cout << "AMateria assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->type = ref.type;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called\n";
}

const std::string& AMateria::getType() const {
    return (this->type);
}