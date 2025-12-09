#include "ScalarConverter.hpp"

void convertFromInt(const std::string& literal)
{
    long value = std::atol(literal.c_str());
    char c = static_cast<char>(value);
    float f = static_cast<float>(value);
    double d = static_cast<double>(value);

    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else if (static_cast<int>(c) > 127 || static_cast<int>(c) < 0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    if (value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << value << std::endl;
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}
void convertFromChar(const std::string& literal)
{
    char c = literal[0];
    int value = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << value << std::endl;
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}
void convertFromSpecial(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
void convertFromFloat(const std::string& literal)
{
    float value = static_cast<float>(std::strtod(literal.c_str(), NULL));
    char c = static_cast<char>(value);
    int i = static_cast<int>(value);
    double d = static_cast<double>(value);

    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else if (static_cast<int>(c) > 127 || static_cast<int>(c) < 0)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    if (value == static_cast<int>(value))
        std::cout << "float: " << value << ".0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void convertFromDouble(const std::string& literal)
{
    double value = std::strtod(literal.c_str(), NULL);
    char c = static_cast<char>(value);
    int i = static_cast<int>(value);
    float f = static_cast<float>(value);

    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else if (static_cast<int>(c) < 127 || static_cast<int>(c) > 0)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (value == static_cast<int>(value))
        std::cout << "double: " << value << ".0" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}