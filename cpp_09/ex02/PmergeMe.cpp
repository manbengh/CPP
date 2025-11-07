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

// template <typename C>
// C mergeAlg(C &leftSide, C &rightSide)
// {
//     C res;

//     typename C::iterator itL = leftSide.begin();
//     typename C::iterator itR = rightSide.begin();

//     while (itL != leftSide.end() && itR != rightSide.end())
//     {
//         if (*itL < *itR)
//             res.push_back(*itL++);
//         else
//             res.push_back(*itR++);
//     }
   
//     while (itL != leftSide.end())
//     {
//         res.push_back(*itL++);
//     }

//     while (itR != rightSide.end())
//     {
//         res.push_back(*itR++);
//     }

//     return res;
// }




template <typename C>
void mergeAlg(C &c, size_t left, size_t mid, size_t right)
{
    C tmp;
    tmp.reserve(right - left); // évite les reallocations (utile pour vector)

    size_t i = left;
    size_t j = mid;

    while (i < mid && j < right)
    {
        if (c[i] <= c[j])
            tmp.push_back(c[i++]);
        else
            tmp.push_back(c[j++]);
    }

    while (i < mid)
        tmp.push_back(c[i++]);
    while (j < right)
        tmp.push_back(c[j++]);

    for (size_t k = 0; k < tmp.size(); ++k)
        c[left + k] = tmp[k];
}


template <typename C>
void mergeInsertSortAlg(C &c, size_t left, size_t right)
{
    size_t size = right - left;
    if (size <= 10)
    {
        for (size_t i = left + 1; i < right; ++i)
        {
            int tmp = c[i];
            size_t j = i;
            while (j > left && c[j - 1] > tmp)
            {
                c[j] = c[j - 1];
                --j;
            }
            c[j] = tmp;
        }
        return;
    }

    size_t mid = left + size / 2;
    mergeInsertSortAlg(c, left, mid);
    mergeInsertSortAlg(c, mid, right);
    mergeAlg(c, left, mid, right);
}


// template <typename C>
// void mergeInsertSortAlg(C &c)
// {
//     if (c.size() <= 5)
//         insertSort(c);
//     else
//     {
//        typename C::iterator middle = c.begin() + c.size() / 2;

//        C leftSide(c.begin(), middle);
//        C rightSide(middle, c.end());

//         mergeInsertSortAlg(leftSide);
//         mergeInsertSortAlg(rightSide);

//        c = mergeAlg(leftSide, rightSide);
//     }
// }



void PmergeMe::mergeInsertSort()
{ 
    printContainer(this->vector, false);

    clock_t startClockVec = clock();
    mergeInsertSortAlg(this->vector, 0, vector.size());
    clock_t endClockVec = clock();

    clock_t startClockDeq = clock();
    mergeInsertSortAlg(this->deque, 0, deque.size());
    clock_t endClockDeq = clock();

    printContainer(this->vector, true);


    double timeVec = static_cast<double>(endClockVec - startClockVec) / CLOCKS_PER_SEC * 1e6;
    // double timeVec = double(endClockVec - startClockVec) / double(CLOCKS_PER_SEC);
    double timeDeq = static_cast<double>(endClockDeq - startClockDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << this->vector.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
