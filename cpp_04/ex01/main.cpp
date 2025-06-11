#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {

    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "Animal type : " << a->getType() << std::endl;
    std::cout << "Dog type    : " << d->getType() << std::endl;
    std::cout << "Cat type    : " << c->getType() << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    a->makeSound(); // Generic
    d->makeSound(); // Woof
    c->makeSound(); // Meow

    std::cout << "\n--- Destruction ---" << std::endl;
    delete a;
    delete d;
    delete c;

    std::cout << "\n--- Tests de copie ---" << std::endl;
    Dog dog1;
    Dog dog2;

    dog2 = dog1;
    std::cout << "dog2 type (après affectation) : " << dog2.getType() << std::endl;

    Cat cat1;
    Cat cat2(cat1);
    std::cout << "cat2 type (copie) : " << cat2.getType() << std::endl;

    WrongAnimal *WAnimal = new WrongCat();
    std::cout << "\n--- Wrong Types ---" << std::endl;
    std::cout << "Wrong Animal type : " << WAnimal->getType() << std::endl;

    std::cout << "\n--- Wrong Sounds ---" << std::endl;
    WAnimal->makeSound(); // Generic
    std::cout << std::endl;

    delete WAnimal;

    std::cout << "\n--- Test Brain (with Cat) ---" << std::endl;

    Cat catA;
    catA.setBrainIdea(0, "Dormir");
    catA.setBrainIdea(1, "Manger");

    std::cout << "catA idée 0 : " << catA.getBrainIdea(0) << std::endl;
    std::cout << "catA idée 1 : " << catA.getBrainIdea(1) << std::endl;

    Cat catB(catA);
    std::cout << "\ncatB idée 1 (copie) : " << catB.getBrainIdea(1) << std::endl;

    catB.setBrainIdea(0, "Chasser");
    std::cout << "catA idée 0 après modif de catB : " << catA.getBrainIdea(0) << std::endl;
    std::cout << "catB idée 0 modifiée : " << catB.getBrainIdea(0) << std::endl;

    return 0;
}
