#include "Span.hpp"

int main() {
    Span container(6);
    container.addNumber(1);
    container.addNumber(3);
    container.addNumber(4);
    container.addNumber(200);
    container.addNumber(201);
    // std::cout << container;
    std::cout << "Shortest distance is == " << container.shortestSpan() << std::endl;
    std::cout << "Longest distance is == " << container.longestSpan() << std::endl;
    std::cout << "-------\n";
    Span container2(6);
    container2.addNumber(container.getBegin(), container.getEnd());
    // container2.addNumber(300);
    // std::cout << container2;
    return (0);
}