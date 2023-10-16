#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed& fixedRef){
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPoint = fixedRef.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixedRef) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixedRef) {
        return (*this);
    }
    this->fixedPoint = fixedRef.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
    this->fixedPoint = raw;
}