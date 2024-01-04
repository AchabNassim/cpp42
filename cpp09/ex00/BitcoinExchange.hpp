#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double>   bitcoinRateDb;
        std::map<std::string, double>   currentDb;
        double                          profit;       
};