#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other){
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called" << std::endl;
}

int check_integer(const std::string& literal)
{
    int i = 0;
    if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos)
        return 6;
    if ((literal[0] == '+' || literal[0] == '-') && literal[1] != '\0')
        i++;
    while (literal[i])
    {
        if (!isdigit(literal[i]))
            return 6;
        i++;
    }
    return 0;
}

int check_float(const std::string& literal)
{
    int i = 0;
    int count_dot = 0;
    int count_digit = 0;
    if (literal.find('.') != std::string::npos && literal[literal.size() - 1] == 'f')
    {
        if ((literal[0] == '+' || literal[0] == '-') && literal[1] != '\0')
            i++;
        while (i < static_cast<int>(literal.size()) - 1)
        {
            if (literal[i] == '.')
                count_dot++;
            else if (isdigit(literal[i]))
                count_digit++;
            else
                return 6;
            i++;
        }
        if (count_dot != 1 || count_digit == 0)
            return 6;
        return 0;
    }
    return 6;
}
int check_double(const std::string& literal)
{
    int i = 0;
    int count_dot = 0;
    int count_digit = 0;
    if (literal.find('.') != std::string::npos)
    {
        if ((literal[0] == '+' || literal[0] == '-') && literal[1] != '\0')
            i++;
        while (i < static_cast<int>(literal.size()))
        {
            if (literal[i] == '.')
                count_dot++;
            else if (isdigit(literal[i]))
                count_digit++;
            else
                return 6;
            i++;
        }
        if (count_dot != 1 || count_digit == 0)
            return 6;
        return 0;
    }
    return 6;
}

int checkType(const std::string& literal){
    if (literal.empty()) {
        return -1; 
    }
    if (literal.length() == 1 && !isdigit(literal[0])) {
        return 2; 
    }
    if (literal == "nan" || literal == "inf" || literal == "-inf" ||
        literal == "nanf" || literal == "inff" || literal == "-inff" ||
        literal == "+inf"  || literal == "+inff") {
        return 3;
    }
    if (check_integer(literal) != 6) {
        return 1; 
    }
    if (check_float(literal) != 6) {
        return 4; 
    }
    if (check_double(literal) != 6) {
        return 5;
    }
    return 0;
}

void ScalarConverter::convert(const std::string& literal)
{
    int type = checkType(literal);
    std::cout << "Detected type code: " << type << std::endl;
    if (type == 1)
    {
        convertFromInt(literal);
    }
    else if (type == 2)
    {
        convertFromChar(literal);
    }
    else if (type == 3)
    {
        convertFromSpecial(literal);
    }
    else if (type == 4)
    {
        convertFromFloat(literal);
    }
    else if (type == 5)
    {
        convertFromDouble(literal);
    }
    else
    {
        std::cout << "Error: Invalid literal" << std::endl;
    }
}