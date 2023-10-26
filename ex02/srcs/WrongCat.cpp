#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << this->m_type << " constructor called\n";
}

WrongCat::WrongCat(WrongCat& ref) {
    std::cout << "WrongCat copy constructor called\n";
    this->m_type = ref.m_type;
}

WrongCat& WrongCat::operator=(WrongCat& ref) {
    std::cout << "WrongCat assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << this->m_type << " destructor called\n";
}

void    WrongCat::makeSound() const {
    std::cout << "[WrongAnimal] " << m_type << " : miaow\n"; 
}