#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        std::cout << argv[1] << std::endl;
        BitcoinExchange bitcoin;
        bitcoin.storeRateDb();
        std::map<std::string, double> map = bitcoin.getRateDb();
        std::cout << map.begin()->first << std::endl;
    }
    return (0);
}