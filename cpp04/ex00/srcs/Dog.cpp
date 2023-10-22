#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << this->m_type << " constructor called\n";
}

Dog::~Dog() {
    std::cout << this->m_type << " destructor called\n";
}

void    Dog::makeSound() const {
    std::cout << "[Animal] " << this->m_type << " : Woof\n"; 
}