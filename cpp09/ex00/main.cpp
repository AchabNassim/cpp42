#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {
    std::ifstream in("test.csv");
    std::string line;
    std::string token;
    std::getline(in, line);
    std::getline(in, line);
    std::stringstream ss(line);
    std::getline(ss, token, '|');
    std::getline(ss, token, '|');
    std::cout << std::stoi(token) << std::endl;
}