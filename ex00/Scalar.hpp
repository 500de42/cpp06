#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>

class ScalarConverter
{
    public :
        static void Convert(std::string nb);
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &src); 
};

#endif
