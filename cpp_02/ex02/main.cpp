#include "Fixed.hpp"


// int main( void )
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }


int main()
{
    Fixed a = 1;
    Fixed b = 1;
    Fixed c = a + b;
    std::cout << c << std::endl;

    c = a - b;
    std::cout << c << std::endl;

    c = Fixed(5.05f) * Fixed(2);
    std::cout << c << std::endl;
}
