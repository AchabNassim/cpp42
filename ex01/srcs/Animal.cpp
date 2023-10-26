#include "../include/Animal.hpp"

Animal::Animal() : m_type("Unknown") {
    std::cout << "Animal constructor called\n";
}

Animal::Animal(std::string type) : m_type(type) {
    std::cout << "Animal constructor called\n";
}

Animal::Animal(Animal& ref) {
    std::cout << "Animal constructor called\n";
    this->m_type = ref.m_type;
}

Animal& Animal::operator=(Animal& ref) {
    std::cout << "Animal assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

void    Animal::makeSound() const {
    std::cout << m_type << " animal made a sound\n";
}

std::string Animal::getType() const {
    return (this->m_type);
}