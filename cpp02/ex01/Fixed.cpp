#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = static_cast<int>(std::round(floatValue * (1 << this->fractionalBits)));
}


Fixed::Fixed(const Fixed& fixedRef){
    // std::cout << "Copy constructor called" << std::endl;
    this->fixedPoint = fixedRef.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixedRef) {
    // std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
    this->fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(getRawBits()) / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
    return (getRawBits() >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}