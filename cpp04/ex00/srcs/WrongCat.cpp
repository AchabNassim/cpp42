#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << this->m_type << " constructor called\n";
}

WrongCat::~WrongCat() {
    std::cout << this->m_type << " destructor called\n";
}

void    WrongCat::makeSound() const {
    std::cout << "[WrongAnimal] " << m_type << " :miaow\n"; 
}