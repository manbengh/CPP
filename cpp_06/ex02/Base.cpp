#include "Base.hpp"
#include "ClassABC.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    switch (random)
    {
        case 0 :
            return (new A);

        case 1 :
            return (new B);

        case 2 :
            return (new C);
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "It's an A !" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "It's a B !" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "It's a C !" << std::endl;
}

void identify(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "---> A " << std::endl;
        (void) a;
        return ;
    }
    catch (...)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "---> B " << std::endl;
            (void) b;
            return ;
        }
        catch(...)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "---> C  " << std::endl;
                (void) c;
                return ;
            }
            catch(...)
            {}
        }
    }
}
