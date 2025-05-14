#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
    public:
        Fixed();
        Fixed& operator=(const Fixed &other);
        Fixed(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif