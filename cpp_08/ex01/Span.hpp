#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>


class Span
{
    private :
        int _n;
        Span();
        std::vector<int> _vec;

    public :
        Span(int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void printV();

        void addNumber(int N);
        // int shortestSpan();
        int longestSpan();


        //Exceptions
        class Full : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Already Full");
                };
        };
        class Empty : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Not enough");
                };
        };
};

#endif