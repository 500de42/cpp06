#include "Base.hpp"

int main()
{
    // {    
    //     A f;
    //     A *a = &f;
    //     A &b = f;
    //     Base *base = generate();
    //     identify(base);
    //     identify(a);
    //     identify(b);
    // }
    // {    
    //     C f;
    //     C *c = &f;
    //     C &b = f;
    //     Base *base = generate();
    //     identify(base);
    //     identify(c);
    //     identify(b);
    // }
    {    
        B f;
        B *ba = &f;
        B &b = f;
        Base *base = generate();
        identify(base);
        identify(ba);
        identify(b);
    }
}
