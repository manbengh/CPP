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
    private :
        std::stack<T> _s;
        
    public:
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack &other){
            this->_s = other._s;
        };
        MutantStack &operator=(const MutantStack &other){
            if (this != &other)
                this->_s = other._s;
            return this;
        };

        typedef typename std::stack<T>::container_type::iterator iterator;

        typename std::stack<T>::container_type::iterator begin()
        {
            return (std::stack<T, typename std::stack<T>::container_type>::c.begin());
        };

        typename std::stack<T>::container_type::iterator end()
        {
            return (std::stack<T, typename std::stack<T>::container_type>::c.end());
        };




        
};

#endif