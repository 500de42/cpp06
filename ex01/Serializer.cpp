#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t ptrr = reinterpret_cast<uintptr_t>(ptr);
    return ptrr;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data *>(raw);
    return data;
}

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &copy)
{
    (void)copy;
}

Serializer::~Serializer()
{

}

Serializer &Serializer::operator=(const Serializer &src)
{
    (void)src;
    return *this;
}
