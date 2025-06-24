#ifndef SCALAR_HPP
#define SCALAR_HPP
# include <stdint.h>
// #include <cstdint>
# include <iostream>
# include "Data.hpp"



class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private :
        Serializer();
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &src);
};

#endif

