#include "Serializer.hpp"

int main ()
{
    Data obj;
    obj.name = "kalvin";
    obj.age = 24;
    Data *data = &obj;
    uintptr_t d;
    
    d = Serializer::serialize(data);
    Data *copy = Serializer::deserialize(d);
    if (copy == data)
        std::cout << "OK – même adresse : " << data << "\n" << copy << "\n" << copy->age << "\n" << copy->name << '\n';
    else
        std::cout << "Erreur : adresses différentes\n";
}
