#include "ScalarConverter.hpp"
#include <exception>
#include <sstream>

void    print_char(char c) {
    if (c != '\0' && c >= 32 && c <= 126)
        std::cout << "char : " << c << std::endl;
    else
        std::cout << "char : non printable" << std::endl;
}

void convertChar(std::string string) {
    if (string.length() == 1)
        print_char(string[0]);
    else {
        try {
            int nb = std::stoi(string);
            if (nb >= 32 && nb <= 126)
                print_char(static_cast<char>(nb));
            else {
                print_char(0);
            }
        } catch (std::exception &e) {
            std::cerr << "char : impossible" << std::endl;
        }
    }
}


void convertToNumber(std::string string) {
    try {
        int nb = std::stoi(string);
        std::cout << "decimal : " << nb << std::endl;
    } catch (std::exception &e) {
        std::cerr << "decimal : impossible" << std::endl;
    }
}

void    convertToFloat(std::string string) {
    try {
        if (string.compare("-inff") == 0 || string.compare("+inff") == 0 || string.compare("nan") == 0)
            std::cout << "float : impossible" << std::endl;
        else
        {
            std::cout << std::fixed << std::setprecision(1);
            float fl = static_cast<float>(std::stof(string));
            std::cout << "float : " << fl << "f" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "float : impossible" << std::endl;
    }
}

void    convertToDouble(std::string string) {
    try {
        if (string.compare("-inff") == 0 || string.compare("+inff") == 0 || string.compare("nan") == 0)
            std::cout << "float : impossible" << std::endl;
        else
        {
            std::cout << std::fixed << std::setprecision(1);
            double dbl = static_cast<double>(std::stod(string));
            std::cout << "double : " << dbl << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "double : impossible" << std::endl;
    }
}

void ScalarConverter::convert(std::string string) {
    convertChar(string);
    convertToNumber(string);
    convertToFloat(string);
    convertToDouble(string);
}
