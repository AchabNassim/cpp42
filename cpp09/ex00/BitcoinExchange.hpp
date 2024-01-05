#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double>   RateDb;
        std::map<std::string, double>   currentDb;
        double                          profit;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange& ref);
        ~BitcoinExchange();

        void    storeRateDb();
        void    storeCurrentDb(std::string filename); 
        const std::map<std::string, double>& getRateDb() const;
        const std::map<std::string, double>& getCurrentDb() const;
        BitcoinExchange& operator=(const BitcoinExchange& ref);
};

std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref);