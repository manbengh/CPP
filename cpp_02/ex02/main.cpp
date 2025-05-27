#include "Fixed.hpp"


int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}


// int main() {
//     Fixed a;

//     std::cout << "a : " << a << std::endl;
//     std::cout << "++a : " << ++a << std::endl;
//     std::cout << "a++ : " << a++ << std::endl;
//     std::cout << "a après a++ : " << a << std::endl;

//     std::cout << "--a : " << --a << std::endl;
//     std::cout << "a-- : " << a-- << std::endl;
//     std::cout << "a après a-- : " << a << std::endl;

//     return 0;
// }


// int main()
// {
//     Fixed a(5);
//     Fixed b(15);

//     std::cout << Fixed::min(a, b) << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
//     // if (a < b)
//     //     std::cout << "a est plus petit que b\n";

//     // if (a == b)
//     //     std::cout << "a et b sont ==\n";
// }

