#include "PmergeMe.hpp"


int main(int ac, char **av) {
    if (ac < 3) {
        std::cerr << "Please enter numbers\n";
        return 0;
    }
    PmergeMe merge(ac, av);
    return 0;
}