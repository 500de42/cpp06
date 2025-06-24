#include "Serializer.hpp"

int main ()
{
    Data obj;
    Data ii;
    Data *iii =  &ii;
    Data *data = &obj;
    uintptr_t d;
    // Serializer n;
    // Serializer x = n;
    // Serializer j (n);

    
    uintptr_t j = Serializer::serialize(iii);
    d = Serializer::serialize(data);
    Data *copy = Serializer::deserialize(j);
    if (copy == data)
        std::cout << "OK – même adresse : " << data << "\n" << copy<< '\n';
    else
        std::cout << "Erreur : adresses différentes\n";
}
