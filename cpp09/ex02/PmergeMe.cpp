#include "PmergeMe.hpp"

int comparisons = 0;

// Constructors
PmergeMe::PmergeMe() {
}

int validInt(std::string value) {
    for (size_t i = 0; i < value.size(); i++) {
        if (!isdigit(value[i]) && value[i] != '+') {
            return (-1);
        }
    }
    return (0);
}

PmergeMe::PmergeMe(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        std::stringstream ssValue(av[i]);
        int value;
        if (validInt(av[i]) == -1 || !(ssValue >> value) || value < 0) {
            std::cerr << "Please enter a valid int array" << std::endl;
            exit (1);
        } else {
            vec.push_back(value);
            deq.push_back(value);
        }
    }
    if (vec.empty() || deq.empty()) {
        std::cerr << "Please enter a valid int array" << std::endl;
        exit (1);
    }
    vectorFordMerge(vec);
}

PmergeMe::PmergeMe(PmergeMe &ref) {
}

PmergeMe::~PmergeMe() {
}

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

// merge algorithm

std::vector<std::vector<int> > PmergeMe::makePairs(std::vector<int> array) {
    std::vector<std::vector<int> > pairs;
    for (int i = 0; i < array.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(array[i]);
        if (i + 1 < array.size()) {
            pair.push_back(array[i + 1]);
        }
        pairs.push_back(pair);
    }
    return (pairs);
}

void sortpair(std::vector<std::vector<int> >& vector) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].size() > 1) {
            if (vector[i][0] > vector[i][1]) {
                std::swap(vector[i][0], vector[i][1]);
            }
        }
    }
}

std::vector<std::vector<int> > merge(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right) {
    std::vector<std::vector<int> > result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i][1] > right[j][1]) {
            result.push_back(right[j]);
            j++;
        } else {
            result.push_back(left[i]);
            i++;
        }
    }
    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());
    return (result);
}

std::vector<std::vector<int> > mergeSortPairs(std::vector<std::vector<int> >& vector) {
    if (vector.size() == 1) {
        return vector;
    }

    int mid = vector.size() / 2;
    std::vector<std::vector<int> > left(vector.begin(), vector.begin() + mid);
    std::vector<std::vector<int> > right(vector.begin() + mid, vector.end());

    std::vector<std::vector<int> > sortedLeft = mergeSortPairs(left);
    std::vector<std::vector<int> > sortedRight = mergeSortPairs(right);

    return (merge(sortedLeft, sortedRight));
}

bool lowerBoundCompare(int a, int b) {
    comparisons++;
    return (a < b);
}

void PmergeMe::vectorFordMerge(std::vector<int> array) {
    int straggler = -1;
    if (array.size() & 1) {
        straggler = array.back();
        array.erase(array.begin() + array.size() - 1);
    }
    std::vector<std::vector<int> > pairs = makePairs(array);
    sortpair(pairs);
    pairs = mergeSortPairs(pairs);
    
}