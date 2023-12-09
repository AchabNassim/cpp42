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
            std::cerr << e.what() << std::endl;
        }
    }
}


void convertToNumber(std::string string) {
    try {
        int nb = std::stoi(string);
        std::cout << "decimal : " << nb << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void    convertToFloat(std::string string) {
    return ;
}

void ScalarConverter::convert(std::string string) {
    convertChar(string);
    convertToNumber(string);
}
