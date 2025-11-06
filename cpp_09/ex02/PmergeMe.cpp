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
void mergeInsertSortAlg(C &c)
{
    if (c.size() <= 10)
        insertSort(c);
    // else
    // {
    //    ;
    // }
   
}



void PmergeMe::mergeInsertSort()
{
    printContainer(this->vector, false);

    mergeInsertSortAlg(this->vector);

    printContainer(this->vector, true);

}