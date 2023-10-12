#include "Harl.hpp"

int calculateAsciiValue (std::string string) {
    int value = 0;
    for (size_t i = 0; i < string.length(); i++) {
        value += string[i];
    }
    return (value);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "A complaint level is required, choose from DEBUG - INFO - WARNING - ERROR" << std::endl;
        return (1);
    }
    Harl karen;
    switch (calculateAsciiValue(argv[1]))
    {
        case DEBUG:
            std::cout << "[ DEBUG ]\n";
            karen.complain("debug");
            break;
        case INFO:
            std::cout << "[ INFO ]\n";
            karen.complain("info");
            break;
        case WARNING:
            std::cout << "[ WARNING ]\n";
            karen.complain("warning");
            break;
        case ERROR:
            std::cout << "[ ERROR ]\n";
            karen.complain("error");
            break;
        default:
            std::cerr << "Invalid argument" << std::endl;
            break;
    }
    return (0);
}