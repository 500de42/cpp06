#include "Base.hpp"
#include <time.h>

Base::~Base()
{
}

Base *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;

    if (i % 3 == 0)
        return new A;
    else if (i % 3 == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "A\n";
    else if (b)
        std::cout << "B\n";
    else if (c)
        std::cout << "C\n";
    else
        std::cout << "null\n";
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        (void)a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        (void)b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C\n";
        (void)c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
