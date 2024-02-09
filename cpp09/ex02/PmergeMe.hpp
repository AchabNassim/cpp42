#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(std::string string);
        ~PmergeMe();
        PmergeMe& operator=(PmergeMe& ref);
};

