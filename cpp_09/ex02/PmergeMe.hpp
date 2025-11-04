#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <stack>

// std::vector
// std::deque

class PmergeMe
{
    private :
        std::vector<int> vector;
        std::deque<int> deque;


    public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();
        
        
        void printContainer(std::vector<int> myVector);
        void parsing(char **av);
};




#endif