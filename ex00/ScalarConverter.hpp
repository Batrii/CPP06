#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};

int checkType(const std::string& literal);
void convertFromInt(const std::string& literal);
void convertFromChar(const std::string& literal);
void convertFromSpecial(const std::string& literal);
void convertFromFloat(const std::string& literal);
void convertFromDouble(const std::string& literal);
#endif