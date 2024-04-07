#pragma once

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        double startTime;

        PmergeMe();
        std::vector<std::vector<int> > makePairs(std::vector<int> array);
        std::deque<std::deque<int> > makePairs(std::deque<int> array);

        std::vector<int> createChain(std::vector<std::vector<int> > pairs, char chain);
        std::deque<int> createChain(std::deque<std::deque<int> > pairs, char chain);

        void vectorFordMerge(std::vector<int> array);
        void dequeFordMerge(std::deque<int> array);

    public:
        PmergeMe(int ac, char **av);
        PmergeMe(PmergeMe &ref);
        ~PmergeMe();
        PmergeMe& operator=(PmergeMe& ref);
};

std::ostream& operator<<(std::ostream &os, std::vector<int> vec);
std::ostream& operator<<(std::ostream &os, std::deque<int> deq);


