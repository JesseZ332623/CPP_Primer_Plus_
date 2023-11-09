#ifndef _MY_ARRAY_H_
#define _MY_ARRAY_H_

#include <iostream>
#include <cstdlib>

namespace MY_STL
{
    template<typename Type, size_t n>
    class Array
    {
        private:
            Type array[n];

        public:
            Array() {}
            explicit Array(const Type & _value);

            virtual Type & operator[](size_t index);
            virtual Type operator[](size_t index) const;
    };

    template<typename Type, size_t n>
    Array<Type, n>::Array(const Type & _value)
    {
        for (size_t index = 0; index < n; ++index)
        {
            array[index] = _value;
        }
    }

    template<typename Type, size_t n>
    Type & Array<Type, n>::operator[](size_t index)
    {
        if (index >= n) 
        { 
            std::cout << "OUT OF RANGE." << std::endl;  
            std::exit(EXIT_FAILURE);
        } 

        return array[index];
    }

    template<typename Type, size_t n>
    Type Array<Type, n>::operator[](size_t index) const
    {
        if (index >= n) 
        { 
            std::cout << "OUT OF RANGE." << std::endl;  
            std::exit(EXIT_FAILURE);
        } 
        
        return array[index];
    }
    
};

#endif //_MY_ARRAY_H_