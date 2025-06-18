#include "AMateria.hpp"
// #include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;
    // return 0;


    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    std::cout << ice->getType() << std::endl;
    std::cout << cure->getType() << std::endl;

    Character* me = new Character("me");

    std::cout << me->getName() << std::endl;

    me->equip(ice);
    me->equip(cure);
    me->use(0, *me);
    // std::cout << test2->use(NULL) << std::endl;

}
