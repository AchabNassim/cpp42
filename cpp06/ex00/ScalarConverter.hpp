#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(std::string string);
};