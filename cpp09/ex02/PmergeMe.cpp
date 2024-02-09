#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream &os, std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        os << vector[i] << " ";
    }
    return (os);
}

std::ostream& operator<<(std::ostream &os, std::deque<int> deque) {
    for (int i = 0; i < deque.size(); i++) {
        os << deque[i] << " ";
    }
    return (os);
}