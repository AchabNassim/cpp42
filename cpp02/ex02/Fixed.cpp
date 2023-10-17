#include "Fixed.hpp"

// ************         Constructors              ************ //

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
    this->fixedPoint = static_cast<int>(std::roundf(floatValue * (1 << this->fractionalBits)));
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


// ************         Member functions              ************ //


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


// ************         Stream extraction operator overload              ************ //

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}


// ************         Static member functions overload              ************ //

Fixed Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return (b);
    } else {
        return (a); 
    }
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return (b);
    } else {
        return (a); 
    }
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return (a);
    } else {
        return (b); 
    }
}

const Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return (a);
    } else {
        return (b); 
    }
}

// ************         Comparison operators overload              ************ //

bool Fixed::operator>(const Fixed& ref) const {
    return (this->fixedPoint > ref.fixedPoint);
}

bool Fixed::operator>=(const Fixed& ref) const {
    return (this->fixedPoint >= ref.fixedPoint);
}

bool Fixed::operator<(const Fixed& ref) const {
    return (this->fixedPoint < ref.fixedPoint);
}

bool Fixed::operator<=(const Fixed& ref) const {
    return (this->fixedPoint <= ref.fixedPoint);
}

bool Fixed::operator==(const Fixed& ref) const {
    return (this->fixedPoint == ref.fixedPoint);
}

bool Fixed::operator!=(const Fixed& ref) const {
    return (this->fixedPoint != ref.fixedPoint);
}

// ************         arithmetic operators overload              ************ //


Fixed& Fixed::operator+(const Fixed& ref) {
    this->fixedPoint  = this->toInt() + ref.toInt();
    return (*this);
}

Fixed& Fixed::operator-(const Fixed& ref) {
    this->fixedPoint  = this->toInt() - ref.toInt();
    return (*this);
}

Fixed& Fixed::operator*(const Fixed& ref) {
    this->fixedPoint  = this->toInt() * ref.toInt();
    return (*this);
}

Fixed& Fixed::operator/(const Fixed& ref) {
    this->fixedPoint  = this->toInt() / ref.toInt();
    return (*this);
}

