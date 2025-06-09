#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "Animal type : " << a->getType() << std::endl;
    std::cout << "Dog type    : " << d->getType() << std::endl;
    std::cout << "Cat type    : " << c->getType() << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    a->makeSound(); // générique
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

    return 0;
}
