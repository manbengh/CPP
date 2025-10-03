#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>
#include <deque>

template<typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack &other) : std::stack<T>(other){};
        MutantStack &operator=(const MutantStack &other){
            if (this != other)
                std::stack<T>::operator=(other);
            return *this;
        };
        ~MutantStack(){};

        typedef typename std::stack<T>::container_type::iterator iterator;

        // typename std::stack<T>::container_type::iterator begin()
        // {
        //     return (std::stack<T, typename std::stack<T>::container_type>::c.begin());
        // };

        // typename std::stack<T>::container_type::iterator end()
        // {
        //     return (std::stack<T, typename std::stack<T>::container_type>::c.end());
        // };

        typename std::stack<T>::container_type::iterator begin()
        {
            return (this->c.begin());
        };

        typename std::stack<T>::container_type::iterator end()
        {
            return (this->c.end());
        };
};

#endif