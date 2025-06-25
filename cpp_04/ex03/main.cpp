#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


// int main()
// {
//     IMateriaSource* src = new MateriaSource();

//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* ice = src->createMateria("ice");
//     AMateria* cure = src->createMateria("cure");
    
//     std::cout << "\n--- Equip ---" << std::endl;
//     me->equip(ice);
//     me->equip(cure);
//     std::cout << "\n--- Ignored Equip ---" << std::endl;
//     me->equip(NULL);

//     std::cout << "\n--- Use ---" << std::endl;
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob); //ice
//     me->use(1, *bob); //cure
//     std::cout << "\n--- Ignored Use ---" << std::endl;
//     me->use(9, *me);

//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("Mob");

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));

    ICharacter* bob = new Character("Bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << std::endl;

    me->unequip(0);
    me->use(0, *bob);

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    AMateria* unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia could not be created" << std::endl;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);

    delete bob;
    delete me;
    delete src;

    return 0;
}



