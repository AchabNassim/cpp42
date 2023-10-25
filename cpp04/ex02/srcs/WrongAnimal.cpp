#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("unknown") {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type) {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& ref) {
    std::cout << "WrongAnimal constructor called\n";
    this->m_type = ref.m_type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& ref) {
    std::cout << "WrongAnimal assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

void    WrongAnimal::makeSound() const {
    std::cout << m_type << " WrongAnimal made a sound\n";
}

std::string WrongAnimal::getType() const {
    return (this->m_type);
}