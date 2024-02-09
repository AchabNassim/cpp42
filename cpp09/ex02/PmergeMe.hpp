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

        PmergeMe();
    public:
        PmergeMe(std::string string);
        ~PmergeMe();
        PmergeMe& operator=(PmergeMe& ref);
};

std::ostream& operator<<(std::ostream &os, std::vector<int> vec);
std::ostream& operator<<(std::ostream &os, std::deque<int> deq);


