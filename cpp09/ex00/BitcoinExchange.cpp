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

std::string    myTrim(std::string &s) {
    int i = 0;
    while (i < s.size() && std::isspace(s[i])) {
        i++;
    }
    s.erase(0, i);
    return (s);
}

int invalid_string(std::string string) {
    for (int i = 0; i < string.size(); i++) {
        if (!isdigit(string[i]) && string[i] != ' ' && string[i] != '\t' && string[i] != '\n') {
            return (1);
        }
    }
    return (0);
}

int check_valid_date(std::string date, char format, int isFeb) {
    double  dateVal;

    if (invalid_string(date))
        return (-1);
    if (format == 'y') {
        dateVal = std::stoi(date);
        if (date.size() != 4 || dateVal > 2024 || dateVal < 2009)
            return (-1);
    } else if (format == 'm') {
        dateVal = std::stoi(date);
        if (date.size() != 2 || dateVal > 12 || dateVal < 1)
            return (-1);
    } else if (format == 'd') {
        dateVal = std::stoi(date);
        if (date.size() != 3 || dateVal > 31 || dateVal < 1 || (isFeb && dateVal > 29))
            return (-1);
    }
    return (0);
}

int check_date(std::string string) {
    std::istringstream format(string);
    std::string buffer;
    int         isFeb = 0;
    int         valid = 0;
    
    while (std::getline(format, buffer, '-')) {
        if (valid == 0) {
            check_valid_date(buffer, 'y', 0);
            valid++;
        } else if (valid == 1) {
            check_valid_date(buffer, 'm', 0);
            if (buffer.compare("02") == 0)
                isFeb = 1;
            valid++;
        } else if (valid == 2) {
            if (isFeb)
                check_valid_date(buffer, 'd', 1);
            else
                check_valid_date(buffer, 'd', 0);
            valid++;
        }
    }
    if (valid != 3)
        return (-1);
    return (0);
}

int check_rate(std::string rate) {
    double  rateVal;
    if (invalid_string(rate))
        return (-1);
    try {
        rateVal = std::stod(rate);
        if (rateVal < 0 || rateVal > 1000)
            return (-1);
    } catch(std::exception &e) {
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

void    BitcoinExchange::storeCurrentDb(std::string filename) {
    std::ifstream   inFile(filename);
    std::string     line;

    if (inFile.fail()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit (1);
    }
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, '|');
        std::getline(ss, rate, '|');
        if (date.compare("date ") != 0 && rate.compare(" value") != 0) {
            try {
                // std::cout << "date == " << date << " rate == " << rate << std::endl;
                if (check_date(date) == -1 || check_rate(rate) == -1) {
                    this->currentDb[myTrim(date)] = -1;
                } else {
                    double  rateVal = std::stod(rate);
                    this->currentDb[myTrim(date)] = rateVal;
                }
            } catch (std::exception &e) {
                this->currentDb[myTrim(date)] = -1;
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
