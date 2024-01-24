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

std::string&    BitcoinExchange::myTrim(std::string &s, char c) {
    size_t  i = 0;
    size_t  j = s.size() - 1;
    while (i < s.size() && std::isspace(s[i])) {
        i++;
    }
    while (j > 0 && std::isspace(s[j])) {
        j--;
    }
    s.erase(0, i);
    if (j > 0 && c == 'd')
        s.erase(j + 1, s.size() - j - 1);
    return (s);
}

int BitcoinExchange::invalid_string(std::string string, char c) {
    int point = 0;
    int sign = 0;
    for (size_t i = 0; i < string.size(); i++) {
        if (c == 'r') {
            if (!isdigit(string[i]) && string[i] != ' ' && string[i] != '\t' && string[i] != '\n' && string[i] != '.' && string[i] != '-')
                return (1);
            else if (string[i] == '.') {
                point++;
            } else if (string[i] == '-') {
                sign++;
            }
        } else {
            if (!isdigit(string[i]) && string[i] != ' ' && string[i] != '\t' && string[i] != '\n') {
                return (1);
            }
        }
    }
    if (c == 'r' && (point > 1 || sign > 1))
        return (-1);
    return (0);
}

int BitcoinExchange::check_delim(std::string string, char c) {
    int occ = 0;
    for (size_t i = 0; i < string.size(); i++) {
        if (string[i] == c)
            occ++;
    }
    if (occ != 1)
        return (-1);
    return (0);
}

int BitcoinExchange::check_date(std::string string) {
    std::istringstream format(string);
    std::string buffer;
    double      dateVal;
    int         isFeb = 0;
    int         valid = 0;
    
    while (std::getline(format, buffer, '-')) {
        if (valid == 0) {
            dateVal = std::stoi(buffer);
            if (invalid_string(buffer, 'd') == -1 || buffer.size() != 4 || dateVal > 2024 || dateVal < 2009) {
                std::cerr << "Error: year is not valid" << std::endl;
                return (-1);
            }
            valid++;
        } else if (valid == 1) {
            dateVal = std::stoi(buffer);
            if (invalid_string(buffer, 'd') == -1 || buffer.size() != 2 || dateVal > 12 || dateVal < 1) {
                std::cerr << "Error: month is not valid" << std::endl;
                return (-1);
            }
            if (buffer.compare("02") == 0)
                isFeb = 1;
            valid++;
        } else if (valid == 2) {
            if (isFeb) {
                dateVal = std::stoi(buffer);
                if (invalid_string(buffer, 'd') == -1 || buffer.size() != 3 || dateVal > 31 || dateVal < 1 || (dateVal > 28 && isFeb)) {
                    std::cerr << "Error: day is not valid" << std::endl;
                    return (-1);
                }
            }
            valid++;
        }
    }
    if (valid != 3)
        return (-1);
    return (0);
}

int BitcoinExchange::check_rate(std::string rate) {
    double  rateVal;
    if (invalid_string(rate, 'r')) {
        std::cout << "Error: bad input\n";
        return (-1);
    }
    try {
        rateVal = std::stod(rate);
        if (rateVal > 1000) {
            std::cout << "Error: too large number\n";
            return (-1);
        } else if (rateVal < 0) {
            std::cout << "Error: not a positive number\n";
            return (-1);
        }
    } catch(std::exception &e) {
        std::cout << "Error: bad input\n";
        return (-1);
    }
    return (0);
}

void    BitcoinExchange::storeRateDb() {
    std::ifstream   inFile("database.csv");
    std::string     line;

    if (inFile.fail()) {
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
            try {
                double  rateVal = std::stod(rate);
                this->RateDb[date] = rateVal;
            } catch (std::exception &e) {
                // std::cout << e.what() << std::endl;
            }
        }
    }
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

    if (inFile.fail()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit (1);
    }
    while (std::getline(inFile, line)) {
        if (this->invalid_string(line, 'r') == -1)
        {
            std::cerr << "Error:bad input" << std::endl;
            continue ;
        }
        if (check_delim(line, '|') == -1) {
            std::cout << "Error: bad input => no delim\n";
            continue ;
        }
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, '|');
        std::getline(ss, rate, '|');
        if (date.compare("date ") != 0 && rate.compare(" value") != 0) {
            myTrim(date, 'd');
            myTrim(rate, 'r');
            try {
                if (check_rate(rate) != -1 && check_date(date) != -1 ) {
                    // std::cout << "date == '" << date << "' rate == '" << rate << "'" << std::endl;
                    double  rateVal = std::stod(rate);
                    findDate(date, rateVal);
                }
            } catch (std::exception &e) {
                // this->currentDb[myTrim(date)] = -1;
            }
        }
    }
}

const std::map<std::string, double>& BitcoinExchange::getRateDb() const {
    return (this->RateDb);
}


std::ostream& operator<<(std::ostream& os, const std::map<std::string, double> &ref) {
    for (std::map<std::string, double>::const_iterator begin = ref.begin(); begin != ref.end(); begin++) {
        os << "date == '" << begin->first << "' -- rate == '" << begin->second << "'" << std::endl;
    }
    return (os);
}
