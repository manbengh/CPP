#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private :

        std::string type;
    
    public :

        Weapon();
        Weapon(const std::string &type);
        ~Weapon();
        const std::string &getType();
        void setType(std::string mytype);

};

#endif