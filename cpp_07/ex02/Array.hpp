#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template<typename T>

class Array
{
    private :
        T *_array;
        int _size;
    
    public :
        Array(): _array(new T[0]), _size(0){};
        Array(unsigned int n) : _array(new T[n]), _size(n){};
        Array(const Array &other) : _array(new T[other._size]), _size(other._size)
        {
            for (int i = 0; i < this->_size; i++)
                this->_array[i] = other._array[i];
        };
        Array &operator=(const Array &other)
        {
            if (this != other)
            {
                _array(new T[other._size]);
                _size(other._size);
                delete[] this->_array;
                for (int i = 0; i < this->_size; i++)
                    this->_array[i] = other._array[i];
            }
            return (*this);
        };
        ~Array()
        {
            delete[] _array;
        };


        class OutOfRange : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Out Of Range");
                };
        };


        T &operator[](const unsigned int n)
        {
            if (n >= _size || n < 0)
                throw OutOfRange();
            return (this->_array[n]);
        };

        // const T &operator[](const unsigned int n)
        // {
        //     if (n >= _size || n < 0)
        //         throw OutOfRange();
        //     return (this->_array[n]);
        // };


        // GET
        unsigned int size() const
        {
            return (this->_size);
        };
};



#endif