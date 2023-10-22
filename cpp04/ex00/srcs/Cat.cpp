#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << this->m_type << " constructor called\n";
}

Cat::~Cat() {
    std::cout << this->m_type << " destructor called\n";
}

void    Cat::makeSound() const {
    std::cout << "[Animal] " << m_type << " : miaow\n"; 
}