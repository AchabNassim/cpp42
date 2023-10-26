#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << this->m_type << " constructor called\n";
}

Dog::Dog(Dog& ref) {
    std::cout << "Dog copy constructor called\n";
    this->m_type = ref.m_type;
}

Dog& Dog::operator=(Dog& ref) {
    std::cout << "Animal assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

Dog::~Dog() {
    std::cout << this->m_type << " destructor called\n";
}

void    Dog::makeSound() const {
    std::cout << "[Animal] " << this->m_type << " : Woof\n"; 
}