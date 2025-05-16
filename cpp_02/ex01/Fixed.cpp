#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_rawBits = other._rawBits;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}




float Fixed::toFloat(void) const
{
    return (static_cast<float>(_rawBits) / _fractionalBits);
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}



std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
