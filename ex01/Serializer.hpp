#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <cstdint>
#include <iostream>
#include "Data.hpp"

typedef struct Data
{
    int t;
}   Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

