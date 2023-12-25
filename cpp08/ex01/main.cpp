#include "Span.hpp"

int main() {
    Span vec(4);
    Span vec2(5);
    vec.addNumber(1);
    vec.addNumber(0);
    vec.addNumber(201);
    vec.addNumber(202);
    // for (int i = 2; i < 10; i++) {
    //     vec.addNumber(i);
    // }
    // std::cout << vec.shortestSpan() << std::endl;
    // std::cout << vec.longestSpan() << std::endl;
    vec2.addNumber(vec.getBegin(), vec.getEnd());
    vec2.print();
    return (0);
}