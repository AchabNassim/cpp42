#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>

class Span {
    private:
        std::list<int>   container;
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
        void    addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
        int     shortestSpan();
        long    longestSpan();

        std::list<int>const& getList() const;
        std::list<int>::const_iterator getBegin() const;
        std::list<int>::const_iterator getEnd() const;
        // overload
        Span& operator=(const Span& ref);
};

std::ofstream& operator<<(std::ofstream &os, const Span &ref);