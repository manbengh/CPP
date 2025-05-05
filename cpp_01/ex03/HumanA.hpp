#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    private :

        std::string name;
        Weapon &myWeapon;
    
    public :

        HumanA(std::string name, Weapon &myWeapon);
        ~HumanA();
        void attack();

};

#endif
