#include "BitcoinExchange.hpp"
// #include <sys/_types/_size_t.h>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string fileName) {
    storeRateDb();
    calculateRate(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    this->RateDb = ref.getRateDb();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    this->RateDb = ref.getRateDb();
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}


// Methods

void    BitcoinExchange::storeRateDb() {
    std::ifstream   inFile("data.csv");
    std::string     line;

    if (!inFile.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        exit (1);
    }
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        if (date.compare("date") != 0 && rate.compare("exchange_rate") != 0) {
            std::stringstream ss;
            double rateValue;
            ss << rate;
            (ss >> rateValue);
            this->RateDb[date] = rateValue;
        }
    }
}

int BitcoinExchange::checkDelim(std::string line) {
    int i = 0;
    int v = 0;
    while (line[i]) {
        if (line[i] == '|')
            v++;
        i++;
    }
    return (v == 1 ? 0 : -1);
}

int BitcoinExchange::isNumber(std::string string, int mode) {
    int point = 0;
    for (int i = 0; i < string.size(); i++) {
        if (!isdigit(string[i])) {
            if ((string[i] == '-' || string[i] == '+') && mode == 1 && i == 0) {
                continue ;
            } else if (string[i] == '.' && mode == 1 && point == 0) {
                point++;
            } else {
                return (1);
            }
        }
    }
    return (0);
}

int BitcoinExchange::checkDate(std::string date) {
    std::stringstream ss;
    std::string buffer;
    int isFeb = 0;
    int v = 0;

    ss << date;
    if (date.size() != 10) {
        std::cerr << "Error: Bad Input: " << date << std::endl;
        return (-1);
    }
    while (std::getline(ss, buffer, '-')) {
        if (v == 0) {
            int value = atoi(buffer.c_str());
            if (buffer.size() != 4 || isNumber(buffer, 0) || (value < 2009 || value > 2024)) {
                std::cerr << "Error: Bad Input: " << date << std::endl;
                return (-1);
            } 
            v++;
        } else if (v == 1) {
            int value = atoi(buffer.c_str());
            if (buffer.size() != 2 || isNumber(buffer, 0) || (value < 1 || value > 12)) {
                std::cerr << "Error: Bad Input: " << date <<  " buffer == \"" << buffer << "\"" <<std::endl;
                return (-1);
            }
            if (value == 2)
                isFeb = 1;
            v++;
        } else if (v == 2) {
            int value = atoi(buffer.c_str());
            if (buffer.size() != 2 || isNumber(buffer, 0) || (value < 1 || value > 31) || isFeb && value > 29) {
                std::cerr << "Error: Bad Input: " << date << std::endl;
                return (-1);
            }
            v++;
        }
    }
    return (0);
}

double BitcoinExchange::checkRate(std::string rate) {
    std::stringstream ss(rate);
    double value;
    if (isNumber(rate, 1) || !(ss >> value)) {
        std::cerr << "Error: bad input\n";
        return (-1);
    } else if (value > 1000) {
        std::cerr << "Error: too large number\n";
        return (-1);
    } else if (value < 0) {
        std::cerr << "Error: not a positive number\n";
        return (-1);
    }
    return (value);
}

void BitcoinExchange::findDate(std::string date, double rate) {

    if (this->RateDb.find(date) != this->RateDb.end())
        std::cout << this->RateDb.find(date)->first << " => " << rate << " = " << this->RateDb.find(date)->second * rate << std::endl;
    else {
        this->RateDb[date] = 0;
        std::map<std::string, double>::iterator it = this->RateDb.find(date);
        std::map<std::string, double>::iterator targetIt = this->RateDb.find(date);
        if (targetIt != this->RateDb.begin())
            --targetIt;
        else
            targetIt++;
        it->second = targetIt->second;
        std::cout << it->first << " => " << rate << " = " << it->second * rate << std::endl;
    }
}

void    BitcoinExchange::calculateRate(std::string filename) {
    std::ifstream   inFile(filename);
    std::string     line;
    int             v = 0;

    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit (1);
    }
    while (std::getline(inFile, line)) {
        if (v == 0 && line.compare("date | value") != 0) {
            std::cerr << "please fix the first line in the database entered\n";
            exit (1);
        }
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, '|');
        std::getline(ss, rate, '|');
        if (checkDelim(line) != 0) {
            std::cout << "Error: bad input " << line << std::endl;
            continue ;
        }
        date.erase(date.find_last_not_of(" ") + 1);
        rate.erase(0, rate.find_last_of(" ") + 1);
        if (v > 0 && checkDate(date) == 0) {
            double rateValue = checkRate(rate);
            if (rateValue != -1) {
                findDate(date, rateValue);
            }
        }
        if (v == 0) {
            v++;
        }
    }
}

const std::map<std::string, double>& BitcoinExchange::getRateDb() const {
    return (this->RateDb);
}


// std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref) {
//     for (std::map<std::string, double>::const_iterator begin = ref.begin(); begin != ref.end(); begin++) {
//         os << "date == '" << begin->first << "' -- rate == '" << begin->second << "'" << std::endl;
//     }
//     return (os);
// }
