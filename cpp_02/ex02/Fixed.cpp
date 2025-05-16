#include "Fixed.hpp"



int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}
