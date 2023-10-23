#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << this->m_type << " constructor called\n";
    this->brain = new Brain;
}

Cat::Cat(Cat& ref) {
    std::cout << "Cat copy constructor called\n";
    this->m_type = ref.m_type;
    this->brain = new Brain(*ref.brain);
}

Cat& Cat::operator=(Cat& ref) {
    std::cout << "Cat assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    this->brain = new Brain(*ref.brain);
    this->brain = ref.brain;
    return (*this);
}

Cat::~Cat() {
    std::cout << this->m_type << " destructor called\n";
}

void    Cat::makeSound() const {
    std::cout << "[Animal] " << m_type << " : miaow\n"; 
}