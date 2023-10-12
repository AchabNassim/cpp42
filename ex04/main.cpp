#include "main.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Please enter a filename, a string to replace and the replacement string" << std::endl;
        return (1);
    }
    std::string fileName = argv[1];
    std::string toReplace = argv[2];
    std::string replacement = argv[3];
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Couldn't open " << fileName << std::endl;
        return (1);
    } else if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty, exiting program." << std::endl;
        return (1);
    }
    std::ofstream outputFile(fileName + ".replace");
    if (!outputFile.is_open()) {
        std::cerr << "Couldn't create " << fileName << std::endl;
        return (1);
    }
    std::string line;
    size_t      pos;
    while (std::getline(inputFile, line)) {
        pos = line.find(toReplace);
        while (pos != std::string::npos) {
            line = line.substr(0, pos) + replacement + line.substr(pos + toReplace.length(), line.length());
            pos = line.find(toReplace);
        }
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
    std::cout << "Replacement completed!";
    return (0);
}