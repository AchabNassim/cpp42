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
        Fixed();
        Fixed(const int);
        Fixed(const float value);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
        ~Fixed();
		int	getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};




#endif