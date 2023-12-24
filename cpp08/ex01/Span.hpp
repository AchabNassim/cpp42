#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        std::vector<int> vec;
        unsigned int     currentIndex;
        unsigned int     size;
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