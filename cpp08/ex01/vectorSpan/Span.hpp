#pragma once

#include <fstream>
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
        void    print();
        void    addNumber(int n);
        void    addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        int     shortestSpan();
        long    longestSpan();

        std::vector<int>const& getVector() const;
        std::vector<int>::const_iterator getBegin() const;
        std::vector<int>::const_iterator getEnd() const;
        // overload
        Span& operator=(const Span& ref);
};

std::ofstream& operator<<(std::ofstream &os, const Span &ref);