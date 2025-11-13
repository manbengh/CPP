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
void fordJohnsonSort(C &c)
{
    if (c.size() <= 1)
        return ;
    C small;
    C big;

    for (size_t i = 0; i < c.size(); i += 2)
    {
        if (i + 1 < c.size())
        {
            typename C::value_type a = c[i];
            typename C::value_type b = c[i + 1];

            if (a > b)
                std::swap(a, b);
           
            small.push_back(a);
            big.push_back(b);
            // std::cout << a << "    " << b << std::endl;
        }
        else
        {
            small.push_back(c[i]);
        }
        // std::cout << std::endl;
    }

    fordJohnsonSort(big);

    C finalRes(big.begin(), big.end());

    //On n’utilise pas C pour jacob, parce qu’il ne contient pas les mêmes types de données :
    // ce ne sont pas des valeurs du tri, mais des indices numériques servant à piloter l’ordre des insertions.
    std::vector<size_t> jacob;
    {
        size_t j1 = 1;
        size_t j2 = 0;
        while (j1 < small.size())
        {
            jacob.push_back(j1);
            size_t tmp = j1;
            j1 = j1 + 2 * j2;
            j2 = tmp;
        }
    }

    std::vector<bool> inserted(small.size(), false);

    for (size_t j = 0; j < jacob.size(); ++j)
    {
        size_t i = jacob[j];
        if (i - 1 < small.size() && !inserted[i - 1])
        {
            typename C::iterator pos = std::lower_bound(finalRes.begin(), finalRes.end(), small[i - 1]);
            finalRes.insert(pos, small[i - 1]);
            inserted[i - 1] = true;
        }
    }

    for (size_t i = 0; i < small.size(); i++)
    {
        if (!inserted[i])
        {
            typename C::iterator pos = std::lower_bound(finalRes.begin(), finalRes.end(), small[i]);
            finalRes.insert(pos, small[i]);
        }
    }

    c.assign(finalRes.begin(), finalRes.end());
}



void PmergeMe::mergeInsertSort()
{
    printContainer(this->vector, false);

    clock_t startClockVec = clock();
    fordJohnsonSort(this->vector);
    clock_t endClockVec = clock();

    clock_t startClockDeq = clock();
    fordJohnsonSort(this->deque);
    clock_t endClockDeq = clock();

    printContainer(this->vector, true);


    double timeVec = static_cast<double>(endClockVec - startClockVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeq = static_cast<double>(endClockDeq - startClockDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout   << "Time to process a range of "
                << this->vector.size()
                << " elements with std::vector : "
                << timeVec / 2000 << " us" << std::endl;
    std::cout   << "Time to process a range of "
                << this->deque.size()
                << " elements with std::deque : "
                << timeDeq / 2000 << " us" << std::endl;
}
