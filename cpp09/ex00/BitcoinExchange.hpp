#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double>   RateDb;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange& ref);
        ~BitcoinExchange();

        void    storeRateDb();
        void    calculateRate(std::string filename); 
        const std::map<std::string, double>& getRateDb() const;
        BitcoinExchange& operator=(const BitcoinExchange& ref);

        std::string&    myTrim(std::string &s, char c);
        int invalid_string(std::string string, char c);
        int check_delim(std::string string, char c);
        int check_date(std::string string);
        int check_rate(std::string rate);
        void findDate(std::string date, double rate);
};

std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref);