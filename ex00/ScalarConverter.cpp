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
int checkType(const std::string& literal){
    if (literal.empty()) {
        return -1; 
    }
    if ((literal[0] >= '0' && literal[0] <= '9') || literal[0] == '-' || literal[0] == '+') {
        return 1; 
    }
    if (literal.length() == 1 && !isdigit(literal[0])) {
        return 2; 
    }
    if (literal == "nan" || literal == "inf" || literal == "-inf" ||
        literal == "nanf" || literal == "inff" || literal == "-inff") {
        return 3;
    }
    if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos) {
        return 4; 
    }
    if (literal.find('.') != std::string::npos) {
        return 5;
    }
    return 0;
}

void ScalarConverter::convert(const std::string& literal)
{
    int type = checkType(literal);
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