#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <limits>

class  Weapon
{
    private:
        std::string type;
    
    public:
        Weapon();
        ~Weapon();
        std::string &Weapon::get_type(void)
    };

#endif
