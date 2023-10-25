#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : m_type("Unknown") {
    std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(std::string type) : m_type(type) {
    std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(AAnimal& ref) {
    std::cout << "AAnimal constructor called\n";
    this->m_type = ref.m_type;
}

AAnimal& AAnimal::operator=(AAnimal& ref) {
    std::cout << "AAnimal assignment operator called\n";
    if (this == &ref)
        return (*this);
    this->m_type = ref.m_type;
    return (*this);
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called\n";
}

std::string AAnimal::getType() const {
    return (this->m_type);
}