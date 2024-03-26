#include "PmergeMe.hpp"
#include <algorithm>

int comparisons = 0;

// Constructors
PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        std::stringstream ssValue(av[i]);
        int value;
        if (!(ssValue >> value) || value < 0) {
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

std::vector<int> buildJacobsthalSequence(int length) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);

    for (int i = 2; i <= length; ++i) {
        sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
    }
    return (sequence);
}

std::vector<int> FordInsertionSort(std::vector<int> main, std::vector<int> pend) {
    std::vector<int> array = main;
    std::vector<int> sequence = buildJacobsthalSequence(pend.size());
    int added = 0;
    std::cout << "pend size == " << pend.size() << std::endl;
    for (int i = 0; i < pend.size(); i++) {
        // std::cout << "i == " << i << std::endl;
        // std::cout << "sequence index == " << sequence[i] << std::endl;
        if (sequence[i] < pend.size()) {
            array.insert(std::lower_bound(array.begin(), array.begin() + sequence[i] + added, pend[sequence[i]]), pend[sequence[i]]);
            added++;
        }
    }
    std::cout << "works\n";
    return (array);
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
    std::vector<int> main;
    std::vector<int> pend;

    for (int i = 0; i < pairs.size(); i++) {
        main.push_back(pairs[i][1]);
        pend.push_back((pairs[i][0]));
    }
    // std::cout << "****** main array ******\n" << main << "************\n";
    // std::cout << "****** pend array ******\n" << pend << "************\n";
    if (straggler != -1) {
        pend.push_back(straggler);
    }
    std::vector<int> sortedArray = FordInsertionSort(main, pend);
    std::cout << "****** sorted array ******\n" << sortedArray << "************\n";
}

