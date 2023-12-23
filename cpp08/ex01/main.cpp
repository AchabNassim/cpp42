#include "Span.hpp"

int main() {
    Span vec(4);
    vec.addNumber(1);
    vec.addNumber(0);
    vec.addNumber(201);
    vec.addNumber(202);
    std::cout << vec.shortestSpan() << std::endl;
    std::cout << vec.longestSpan() << std::endl;
    return (0);
}