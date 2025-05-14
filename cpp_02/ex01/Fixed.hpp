#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
    public:
        Fixed();
        // Fixed()
        Fixed& operator=(const Fixed &other);
        Fixed(const Fixed &other);
        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;
};


#endif