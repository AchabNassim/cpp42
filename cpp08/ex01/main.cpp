// #include "Span.hpp"
#include "Span2.hpp"

int main() {
    Span container(6);
    Span container2(6);
    container.addNumber(1);
    container.addNumber(3);
    container.addNumber(4);
    container.addNumber(200);
    container.addNumber(201);
    container.print();
    std::cout << "Shortest distance is == " << container.shortestSpan() << std::endl;
    std::cout << "Longest distance is == " << container.longestSpan() << std::endl;
    std::cout << "-------\n";
    container2.addNumber(container.getBegin(), container.getEnd());
    container2.addNumber(300);
    container2.print();
    return (0);
}