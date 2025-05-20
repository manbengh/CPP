#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:

        int _rawBits;
        static const int _fractionalBits = 8;

    public:

        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif