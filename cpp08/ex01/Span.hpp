#pragma once

#include <iostream>
#include <vector>
#include <Algorithm>

class Span {
    private:
        std::vector<int> array;
    public:
        // constructors
        Span();
        Span(unsigned int n);
        Span(const Span& ref);
        ~Span();

        // methods
        void    addNumber(int n);
        int     shortestSpan();
        long    longestSpan();
};