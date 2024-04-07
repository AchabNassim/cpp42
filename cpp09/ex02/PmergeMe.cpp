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
    dequeFordMerge(deq);
}

PmergeMe::PmergeMe(PmergeMe &ref) {
    this->vec = ref.vec;
    this->deq = ref.deq;
}

PmergeMe::~PmergeMe() {
}

PmergeMe&  PmergeMe::operator=(PmergeMe &ref) {
    this->vec = ref.vec;
    this->deq = ref.deq;
    return (*this);
}

std::ostream& operator<<(std::ostream &os, std::vector<int> vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        os << vector[i] << " ";
    }
    return (os);
}

std::ostream& operator<<(std::ostream &os, std::deque<int> deque) {
    for (size_t i = 0; i < deque.size(); i++) {
        os << deque[i] << " ";
    }
    return (os);
}

// merge algorithm

std::vector<std::vector<int> > PmergeMe::makePairs(std::vector<int> array) {
    std::vector<std::vector<int> > pairs;
    for (size_t i = 0; i < array.size(); i += 2) {
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
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector[i].size() > 1) {
            if (vector[i][0] > vector[i][1]) {
                comparisons++;
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
            comparisons++;
            result.push_back(right[j]);
            j++;
        } else {
            comparisons++;
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

std::vector<int> PmergeMe::createChain(std::vector<std::vector<int> > pairs, char chain) {
    std::vector<int> vec;
    for (size_t i = 0; i < pairs.size(); i++) {
        if (chain == 'm') {
            vec.push_back(pairs[i][1]);
        } else {
            vec.push_back(pairs[i][0]);
        }
    }
    return (vec);
} 

void jacobsthalInsertion(std::vector<int>& pend, std::vector<int>& main) {
    unsigned int seq[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
                             5461, 10923, 21845, 43691, 87381, 174763, 349525};
    size_t one = 1;
    size_t two = 0;
    size_t sum = 0;
    size_t counter_seq = 0;
    for (size_t kr = 1; kr < pend.size(); kr++)
    {
        one = seq[counter_seq + 1];
        two = seq[counter_seq] + 1; 
        if (one > pend.size())
            one = pend.size();
        if (two > one)
            break;
        std::vector<std::vector<int> >::iterator it;
        while (one >= two) 
        {
            std::vector<int>::iterator it = std::lower_bound(main.begin(), main.begin() + (one + sum), pend[one - 1], lowerBoundCompare);
            main.insert(it, pend[one - 1]);
            sum++;
            one--;
        }
        counter_seq++;
    }
}

void PmergeMe::vectorFordMerge(std::vector<int> array) {
    clock_t start = clock();
    int straggler = -1;
    if (array.size() & 1) {
        straggler = array.back();
        array.erase(array.begin() + array.size() - 1);
    }
    std::vector<std::vector<int> > pairs = makePairs(array);
    sortpair(pairs);
    pairs = mergeSortPairs(pairs);

    // insertion phase
    std::vector<int> main = createChain(pairs, 'm');
    std::vector<int> pend = createChain(pairs, 'p');
    // std::cout << "main chain == " << main << std::endl;
    // std::cout << "pend chain == " << pend << std::endl;
    
    main.insert(main.begin(), pend[0]);
    jacobsthalInsertion(pend, main);
    if (straggler != - 1) {
        main.insert(std::lower_bound(main.begin(), main.end(), straggler, lowerBoundCompare), straggler);
    }
    clock_t end = clock();
    double duration = (double)((end - start)) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "sorted array = " << main << std::endl;
    std::cout << "[vector] time to process range of " << array.size() + 1 << " is " << duration << " microsecond" << std::endl;
}

// deque part

std::deque<std::deque<int> > PmergeMe::makePairs(std::deque<int> array) {
    std::deque<std::deque<int> > pairs;
    for (size_t i = 0; i < array.size(); i += 2) {
        std::deque<int> pair;
        pair.push_back(array[i]);
        if (i + 1 < array.size()) {
            pair.push_back(array[i + 1]);
        }
        pairs.push_back(pair);
    }
    return (pairs);
}

void sortpair(std::deque<std::deque<int> >& deque) {
    for (size_t i = 0; i < deque.size(); i++) {
        if (deque[i].size() > 1) {
            if (deque[i][0] > deque[i][1]) {
                comparisons++;
                std::swap(deque[i][0], deque[i][1]);
            }
        }
    }
}

std::deque<std::deque<int> > merge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right) {
    std::deque<std::deque<int> > result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i][1] > right[j][1]) {
            comparisons++;
            result.push_back(right[j]);
            j++;
        } else {
            comparisons++;
            result.push_back(left[i]);
            i++;
        }
    }
    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());
    return (result);
}

std::deque<std::deque<int> > mergeSortPairs(std::deque<std::deque<int> >& deque) {
    if (deque.size() == 1) {
        return deque;
    }

    int mid = deque.size() / 2;
    std::deque<std::deque<int> > left(deque.begin(), deque.begin() + mid);
    std::deque<std::deque<int> > right(deque.begin() + mid, deque.end());

    std::deque<std::deque<int> > sortedLeft = mergeSortPairs(left);
    std::deque<std::deque<int> > sortedRight = mergeSortPairs(right);

    return (merge(sortedLeft, sortedRight));
}


std::deque<int> PmergeMe::createChain(std::deque<std::deque<int> > pairs, char chain) {
    std::deque<int> vec;
    for (size_t i = 0; i < pairs.size(); i++) {
        if (chain == 'm') {
            vec.push_back(pairs[i][1]);
        } else {
            vec.push_back(pairs[i][0]);
        }
    }
    return (vec);
} 

void jacobsthalInsertion(std::deque<int>& pend, std::deque<int>& main) {
    unsigned int seq[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
                             5461, 10923, 21845, 43691, 87381, 174763, 349525};
    size_t one = 1;
    size_t two = 0;
    size_t sum = 0;
    size_t counter_seq = 0;
    for (size_t kr = 1; kr < pend.size(); kr++)
    {
        one = seq[counter_seq + 1];
        two = seq[counter_seq] + 1; 
        if (one > pend.size())
            one = pend.size();
        if (two > one)
            break;
        std::deque<std::deque<int> >::iterator it;
        while (one >= two) 
        {
            std::deque<int>::iterator it = std::lower_bound(main.begin(), main.begin() + (one + sum), pend[one - 1], lowerBoundCompare);
            main.insert(it, pend[one - 1]);
            sum++;
            one--;
        }
        counter_seq++;
    }
}

void PmergeMe::dequeFordMerge(std::deque<int> array) {
    clock_t start = clock();
    int straggler = -1;
    if (array.size() & 1) {
        straggler = array.back();
        array.erase(array.begin() + array.size() - 1);
    }
    std::deque<std::deque<int> > pairs = makePairs(array);
    sortpair(pairs);
    pairs = mergeSortPairs(pairs);

    // insertion phase
    std::deque<int> main = createChain(pairs, 'm');
    std::deque<int> pend = createChain(pairs, 'p');
    // std::cout << "main chain == " << main << std::endl;
    // std::cout << "pend chain == " << pend << std::endl;
    
    main.insert(main.begin(), pend[0]);
    jacobsthalInsertion(pend, main);
    if (straggler != - 1) {
        main.insert(std::lower_bound(main.begin(), main.end(), straggler, lowerBoundCompare), straggler);
    }
    clock_t end = clock();
    double duration = (double)((end - start)) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "sorted array = " << main << std::endl;
    std::cout << "[deque] time to process range of " << array.size() + 1 << " is " << duration << " microsecond" << std::endl;
}