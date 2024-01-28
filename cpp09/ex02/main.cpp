#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int comparisons = 0;
std::ostream& operator<<(std::ostream &os, std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        os << vector[i] << " ";
    }
    // os << std::endl;
    return (os);
}

std::ostream& operator<<(std::ostream &os, std::vector<std::vector<int> > vector) {
    for (int i = 0; i < vector.size(); i++) {
        os << vector[i] << " | ";
    }
    os << std::endl;
    return (os);
}

std::vector<std::vector<int> > merge(const std::vector<std::vector<int> >& left, const std::vector<std::vector<int> >& right) {
    std::vector<std::vector<int> > result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i][1] < right[j][1]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }
        comparisons++;
    }

    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());

    return result;
}

std::vector<std::vector<int> > mergeSort(const std::vector<std::vector<int> >& vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    size_t middle = vec.size() / 2;
    std::vector<std::vector<int> > left(vec.begin(), vec.begin() + middle);
    std::vector<std::vector<int> > right(vec.begin() + middle, vec.end());

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

void sortPair(std::vector<int> &pair) {
    if (pair.size() > 1) {
        if (pair[1] < pair[0]) {
            std::swap(pair[0], pair[1]);
            comparisons++;
        }
    }
}

bool comparefirstElement(std::vector<int> &first, std::vector<int> &second) {
    comparisons++;
    return (first[1] < second[1]);
}

bool lowerBoundCompare(int a, int b) {
    comparisons++;
    return (a < b);
}

void makePairs(std::vector<std::vector<int> > &pairs, std::vector<int> &array) {
    for (int i = 0; i < array.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(array[i]);
        if (i + 1 < array.size()) {
            pair.push_back(array[i + 1]);
        }
        sortPair(pair);
        pairs.push_back(pair);
    }
}

void    fillChains(std::vector<std::vector<int> > &pairs,std::vector<int> &main, std::vector<int> &pend) {
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].size() == 2) {
            main.push_back(pairs[i][1]);
            pend.push_back(pairs[i][0]);
        }
    }
}

std::vector<int> buildJacobsthalSequence(int length) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);

    for (int i = 2; i <= length; ++i) {
        sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
    }

    return sequence;
}

// Function to implement the Merge Insertion Sort algorithm
void mergeInsertionSort(std::vector<int>& vec) {
    int straggler = -1;
    std::vector<std::vector<int> > pairs;
    std::vector<int> main;
    std::vector<int> pend;
    
    if (vec.size() % 2 != 0) {
        straggler = vec.back();
        vec.pop_back();
    }
    makePairs(pairs, vec);
    pairs = mergeSort(pairs);
    fillChains(pairs, main, pend);
    main.insert(main.begin(), pend[0]);
    pend.erase(pend.begin());
    std::vector<int> jacobsthalSeq = buildJacobsthalSequence(pend.size());
    for (int i = 0; pend.size() > 0; i++) {
        int index = jacobsthalSeq[i]; 
        if (index < pend.size()) {
            main.insert(std::lower_bound(main.begin(), main.end(), pend[index], lowerBoundCompare), pend[index]);
            pend.erase(pend.begin() + index);
        }
    }
    if (straggler != -1)
        main.insert(std::lower_bound(main.begin(), main.end(), straggler, lowerBoundCompare), straggler);
    std::cout << main << std::endl;
    std::cout << pend << std::endl;
}

int main() {
    int arr[] = {5, 18, 27, 42, 14, 63, 91, 20, 7, 55, 33, 77, 12, 48, 30, 8, 16, 92, 41, 25, 60};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    

    mergeInsertionSort(vec);
    std::cout << "Number of comparisons == " << comparisons << std::endl;
    return 0;
}