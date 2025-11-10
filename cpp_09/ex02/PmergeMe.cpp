#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    this->deque = other.deque;
    this->vector = other.vector;
    return *this;
}

PmergeMe::~PmergeMe(){}

// --------------------------------------------



void PmergeMe::printContainer(std::vector<int> myVector, bool status)
{
    if (!status)
        std::cout << "Before :   ";
    else
        std::cout << "After :   ";
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}


void PmergeMe::parsing(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        std::string arg(av[i]);
        // std::cout << arg << std::endl;

        int signNum = 0;
        for (int j = 0; arg[j]; j++)
        {
            if (arg[j] == '+' || arg[j] == '-')
            {
                if (j != 0 || ++signNum > 1)
                    throw std::invalid_argument("Error : Invalid arg");
            }
            else if (!isdigit(arg[j]))
                throw std::invalid_argument("Error : Invalid arg");
        }

        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::invalid_argument("Error : No negative numbers");
       
        for (int a = i + 1; av[a]; a++)
        {
            if (std::atoi(av[a]) == num)
                throw std::invalid_argument("Error : Duplicates detected");
        }
        vector.push_back(num);
        deque.push_back(num);
    }
    // printContainer(vector);
}

template <typename C>
void insertSort(C &c)
{
    for (size_t i = 1; i < c.size(); ++i)
    {
        int tmp = c[i];
        size_t j = i;

        while (j > 0 && c[j - 1] > tmp)
        {
            c[j] = c[j - 1];
            --j;
        }
        c[j] = tmp;
    }
}

template <typename C>
C mergeAlg(C &leftSide, C &rightSide)
{
    C res;

    typename C::iterator itL = leftSide.begin();
    typename C::iterator itR = rightSide.begin();

    while (itL != leftSide.end() && itR != rightSide.end())
    {
        if (*itL < *itR)
            res.push_back(*itL++);
        else
            res.push_back(*itR++);
    }
   
    while (itL != leftSide.end())
    {
        res.push_back(*itL++);
    }

    while (itR != rightSide.end())
    {
        res.push_back(*itR++);
    }

    return res;
}


template <typename C>
void mergeInsertSortAlg(C &c)
{
    if (c.size() <= 5)
        insertSort(c);
    else
    {
       typename C::iterator middle = c.begin() + c.size() / 2;

       C leftSide(c.begin(), middle);
       C rightSide(middle, c.end());

        mergeInsertSortAlg(leftSide);
        mergeInsertSortAlg(rightSide);

       c = mergeAlg(leftSide, rightSide);
    }
}


void PmergeMe::mergeInsertSort()
{ 
    printContainer(this->vector, false);

    clock_t startClockVec = clock();
    mergeInsertSortAlg(this->vector);
    clock_t endClockVec = clock();

    clock_t startClockDeq = clock();
    mergeInsertSortAlg(this->deque);
    clock_t endClockDeq = clock();

    printContainer(this->vector, true);


    double timeVec = static_cast<double>(endClockVec - startClockVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeq = static_cast<double>(endClockDeq - startClockDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << this->vector.size() << " elements with std::vector : " << timeVec / 1000 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque : " << timeDeq / 1000 << " us" << std::endl;
}
