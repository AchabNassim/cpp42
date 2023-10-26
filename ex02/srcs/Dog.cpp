#include "../include/Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout << this->m_type << " constructor called\n";
    this->brain = new Brain;
}

Dog::Dog(Dog& ref) {
    std::cout << "Dog copy constructor called\n";
    this->m_type = ref.m_type;
    this->brain = new Brain(*ref.brain);
}

Dog& Dog::operator=(Dog& ref) {
    std::cout << "Animal assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    delete this->brain;
    this->brain = new Brain(*ref.brain);
    this->brain = ref.brain;
    return (*this);
}

Dog::~Dog() {
    std::cout << this->m_type << " destructor called\n";
    delete this->brain;
}

void    Dog::makeSound() const {
    std::cout << "[Animal] " << this->m_type << " : Woof\n"; 
}