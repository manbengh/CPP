#include "Base.hpp"
#include "ClassABC.hpp"

int main()
{
    Base *test;
    test = generate();
    identify(test);
    identify(*test);
    delete (test);
}
