#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
    _rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->_rawBits = other._rawBits;
    }
    return (*this);
}

Fixed::~Fixed()
{
}




int Fixed::getRawBits(void)const
{
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_rawBits) / _fractionalBits);
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}




Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(this->_rawBits + other._rawBits);
    return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(this->_rawBits - other._rawBits);
    return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;

    res.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
    return (res);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
