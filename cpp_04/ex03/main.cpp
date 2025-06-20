#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());  // materiaSource FULL

    ICharacter* me = new Character("Arthur");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire"); //NULL

    me->equip(ice);
    me->equip(cure);
    // for (int i = 2 ; i < 70 ; i++)
    // {
    //     me->equip(new Ice());
    //     me->unequip(i);
    // }
    me->equip(unknown);  // ignoré

    me->equip(NULL);


    me->use(0, *me);
    me->use(1, *me);
    me->use(3, *me);  // Index invalide
    me->use(42, *me); // Index invalide


    me->unequip(1);
    // delete cure; // nécessaire si on a unequip

    ICharacter* enemy = new Character("Enemy");


    me->use(0, *enemy);  // Ice
    me->use(1, *enemy);  // Slot vide (unequip)

    delete enemy;
    // delete cure;
    delete me;
    delete src;

    return 0;
}




// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;




//     // AMateria* ice = new Ice();
//     // AMateria* cure = new Cure();
//     // std::cout << ice->getType() << std::endl;
//     // std::cout << cure->getType() << std::endl;

//     // Character* me = new Character("me");

//     // std::cout << me->getName() << std::endl;

//     // me->equip(ice);
//     // me->equip(cure);
//     // me->use(0, *me);

    // me->unequip(1);

    // delete(me);
// }
