#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

class NotFound : public std::exception
{
    public :
        const char *what() const throw()
        {
            return ("Not Found");
        }
};

template <typename T>

typename T::const_iterator easyfind(const T &tab, int i)
{
    typename T::const_iterator found = std::find(tab.begin(), tab.end(), i);
    if (found == tab.end())
    {
        throw NotFound();
    }
    return found;
};


#endif