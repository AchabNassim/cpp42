#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        BitcoinExchange bitcoin(argv[1]);
    } else {
        std::cerr << "Error: Please enter a database" << std::endl;
    }
    return (0);
}