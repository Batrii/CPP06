#include "Serializer.hpp"
#include "Data.hpp"


int main()
{
    Data Data1;

    Data1.n = 10;
    Data1.str = "badr";
    std::cout << "Data1 address: " << &Data1 << std::endl;

    uintptr_t raw = Serializer::serialize(&Data1);
    std::cout << "Serialized Data1 to raw: " << raw << std::endl;
    Data* Data2 = Serializer::deserialize(raw);
    std::cout << "Deserialized raw to Data2 address: " << Data2 << std::endl;
    std::cout << "Data2 contents - n: " << Data2->n << ", str: " << Data2->str << std::endl;

    return 0;
}