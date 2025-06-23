#include "Serializer.hpp"

int main ()
{
    Data *data = NULL;
    uintptr_t d;

    d = Serializer::serialize(data);
    if (data != (Data *)d)
        std::cout << " no\n";
    else
        std::cout << d <<"\n" << &data;
}

