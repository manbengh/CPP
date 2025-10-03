#include "Span.hpp"

Span::Span()
{
    _n = 0;
}

Span::Span(int N)
{
    _n = N;
}

Span::Span(const Span &other)
{
    this->_n = other._n;
    this->_vec = other._vec;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_n = other._n;
        this->_vec = other._vec;
    }
    return (*this);
}

Span::~Span()
{}

void Span::printV()
{
    for (unsigned long i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i] << std::endl;
    }
}

void Span::addNumber(int N)
{
    // std::cout << "_n ---> " << this->_n << std::endl;
    // std::cout << "size ---> " << this->_vec.size() << std::endl;
    if (this->_vec.size() > (unsigned long)this->_n)
    {
        throw Full();
    }
    _vec.push_back(N);
}

void printTest(std::vector<int> test)
{
    for (unsigned long i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << std::endl;
    }
}

int Span::longestSpan()
{
    if (this->_vec.size() < 2)
        throw Empty();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    return (tmp.back() - tmp.front());
}

int Span::shortestSpan()
{
    if (this->_vec.size() < 2)
        throw Empty();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());

    std::vector<int>::iterator it1 = tmp.begin();
    std::vector<int>::iterator it2 = it1;
    it2++;
    int myMin = *it2 - *it1;
    while (it2 != tmp.end())
    {
        if (myMin > *it2 - *it1)
            myMin = *it2 - *it1;
        it2++;
        it1++;
    }
    return (myMin);
}


void Span::rangeIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        this->addNumber(*begin);
        // std::cout << "range --> " << *begin << std::endl;
        begin++;
    }
    // printTest(*begin);
}

