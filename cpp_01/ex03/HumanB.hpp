#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    private :

        std::string name;
        Weapon *myWeapon;
    
    public :

        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &myWeapon);

};

#endif