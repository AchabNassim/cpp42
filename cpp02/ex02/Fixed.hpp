#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
       int				fixedPoint;
       static const int	fractionalBits = 8; 
    public:
        // constructors and assignement operator
        Fixed();
        Fixed(const int);
        Fixed(const float value);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
        ~Fixed();

        // Normal member functions

		int	getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // Comparison Operator overload
        bool operator>(const Fixed& ref) const;
        bool operator>=(const Fixed& ref) const;
        bool operator<(const Fixed& ref) const;
        bool operator<=(const Fixed& ref) const;
        bool operator==(const Fixed& ref) const;
        bool operator!=(const Fixed& ref) const;

        // Arithmetic operator overload
        Fixed operator+(const Fixed& ref);
        Fixed operator-(const Fixed& ref);
        Fixed operator*(const Fixed& ref);
        Fixed operator/(const Fixed& ref);

        // Increment operator overload


        // Function overload
        static Fixed min(Fixed& a, Fixed& b);
        const static Fixed min(const Fixed& a, const Fixed& b);
        static Fixed max(Fixed& a, Fixed& b);
        const static Fixed max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif