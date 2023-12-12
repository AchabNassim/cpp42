#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(std::string string);
};