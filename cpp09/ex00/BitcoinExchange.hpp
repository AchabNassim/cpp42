#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double>   RateDb;

        void    storeRateDb();

        // parsing methods
        int checkDelim(std::string line);
        int isNumber(std::string string, int mode);
        int checkDate(std::string date);
        double checkRate(std::string rate);
        
        // main methods
        void    calculateRate(std::string filename); 
        void findDate(std::string date, double rate);
    public:
        BitcoinExchange();
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange& ref);
        ~BitcoinExchange();

        const std::map<std::string, double>& getRateDb() const;
        BitcoinExchange& operator=(const BitcoinExchange& ref);
};

// std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref);