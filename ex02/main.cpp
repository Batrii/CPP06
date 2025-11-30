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
    return 0;
}