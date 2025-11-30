#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
    std::cout << "Base destructor called" << std::endl;
}

Base* generate(void){
    int res = rand() % 3;
    if (res == 0)
        return new A();
    else if (res == 1)
        return new B();
    else
        return new C();
    return NULL;
}

void identify(Base* p){
    A* first = dynamic_cast<A*>(p);
    B* second = dynamic_cast<B*>(p);
    C* third = dynamic_cast<C*>(p);

    if (first != NULL)
        std::cout << "type of object is A" << std::endl;
    if (second != NULL)
        std::cout << "type of object is B" << std::endl;
    if (third != NULL)
        std::cout << "type of object is C" << std::endl;
}

void identify(Base& p){
    try{
        A& first = dynamic_cast<A&>(p);
        std::cout << "type of object is A" << std::endl;
        (void)first;
    }catch(const std::exception &e)
    {
        try{
            B& second = dynamic_cast<B&>(p);
            std::cout << "type of object is B" << std::endl;
            (void)second;
        }
        catch(const std::exception &e)
        {
            try{
                C& third = dynamic_cast<C&>(p);
                std::cout << "type of object is C" << std::endl;
                (void)third;
            }
            catch(const std::exception &e)
            {
                std::cout << "no type is matched because" << e.what() << std::endl;
            }
        }
    }
}