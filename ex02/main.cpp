#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



int main()
{
    srand(time(NULL));
    Base *base = generate();
    Base &base2 = *base;

    identify(base);
    identify(base2);
    delete base;

    // -------------------------
        A a;
        B b;
        C c;
        identify(&a);
        identify(&b);
        identify(&c);
        identify(a);
        identify(b);
        identify(c);
    return 0;
}