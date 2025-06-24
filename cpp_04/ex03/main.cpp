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
//     // src->learnMateria(new Ice());  // materiaSource FULL

//     ICharacter* me = new Character("Arthur");

//     AMateria* ice = src->createMateria("ice");
//     AMateria* cure = src->createMateria("cure");
//     AMateria* unknown = src->createMateria("fire"); //NULL

//     std::cout << "\n--- Equip ---" << std::endl;
//     me->equip(ice);
//     me->equip(cure);
//     std::cout << "--- Ignored Equip ---" << std::endl;
//     me->equip(unknown);
//     me->equip(NULL);

//     std::cout << "\n--- Use ---" << std::endl;
//     me->use(0, *me);
//     me->use(1, *me);
//     std::cout << "--- Invalid Use ---" << std::endl;
//     me->use(3, *me);
//     me->use(42, *me);

//     me->unequip(1);

//     ICharacter* enemy = new Character("Enemy");

//     me->use(0, *enemy);  // Ice
//     me->use(1, *enemy);  // Slot vide (unequip)

//     delete enemy;
//     delete cure;
//     delete ice;
//     delete me;
//     delete src;

//     return 0;
// }


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
