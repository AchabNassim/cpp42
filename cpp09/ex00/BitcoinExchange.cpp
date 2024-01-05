#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string fileName) {
    storeRateDb();
    storeCurrentDb(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    this->RateDb = ref.getRateDb();
    this->currentDb = ref.getCurrentDb();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    this->RateDb = ref.getRateDb();
    this->currentDb = ref.getCurrentDb();
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}


// Methods

std::string&    myTrim(std::string &s) {
    int i = 0;
    while (i < s.size() && std::isspace(s[i])) {
        i++;
    }
    s.erase(0, i);
    std::cout << s << std::endl;
    return (s);
}

int invalid_string(std::string date) {
    for (int i = 0; i < date.size(); i++) {
        if (!isdigit(date[i]) && date[i] != ' ' && date[i] != '\t' && date[i] != '\n')
            return (1);
    }
    return (0);
}

int check_valid_date(std::string date, char format) {
    double  dateVal;
    size_t  pos;

    if (invalid_string(date))
        return (-1);
    if (format == 'y') {
        try {
            dateVal = std::stoi(date, &pos);
            if (pos != 4 || dateVal > 2024 || dateVal < 2009)
                return (-1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}

// int check_date(std::istream format) {
//     std::string buffer;
//     int         valid = 0;
    
//     while (std::getline(format, buffer, '-')) {

//     }
// }

void    BitcoinExchange::storeRateDb() {
    std::ifstream   inFile("database.csv");
    std::string     line;

    if (inFile.fail()) {
        exit (1);
    }
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        if (date.compare("date") != 0 && date.compare("exchange_rate") != 0) {
            try {
                size_t  pos;
                double  rateVal = std::stod(rate, &pos);
                if (pos != rate.size())
                    throw std::invalid_argument("Invalid rate format");
                this->RateDb[date] = rateVal;
            } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

void    BitcoinExchange::storeCurrentDb(std::string filename) {
    std::ifstream   inFile(filename);
    std::string     line;

    if (inFile.fail()) {
        exit (1);
    }
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        if (date.compare("date") != 0 && rate.compare("exchange_rate") != 0) {
            try {
                if (invalid_string(rate)) {
                    this->RateDb[myTrim(date)] = -1;
                } else {
                    size_t  pos;
                    double  rateVal = std::stod(rate, &pos);
                    if (pos != rate.size())
                        throw std::exception();
                    this->RateDb[myTrim(date)] = rateVal;
                }
            } catch (std::exception &e) {
                this->RateDb[myTrim(date)] = -1;
            }
        }
    }
}

const std::map<std::string, double>& BitcoinExchange::getRateDb() const {
    return (this->RateDb);
}

const std::map<std::string, double>& BitcoinExchange::getCurrentDb() const {
    return (this->currentDb);
}


std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref) {
    for (std::map<std::string, double>::const_iterator begin = ref.begin(); begin != ref.end(); begin++) {
        os << "date == " << begin->first << " -- rate == " << begin->second << std::endl;
    }
    return (os);
}
