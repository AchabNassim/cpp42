#include <iostream>
#include <vector>
#include <algorithm>

int comparisons = 0;
std::ostream& operator<<(std::ostream &os, std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        os << vector[i] << " ";
    }
    os << std::endl;
    return (os);
}

void binaryInsertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int low = 0, high = i - 1;

        while (low <= high) {
            comparisons++;
            int mid = (low + high) / 2;
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for (int j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
        }
        arr[low] = key;
    }
}


void sortPair(std::vector<int> &pair) {
    for (int i = 0; i < pair.size(); i++) {
        if (i + 1 < pair.size()) {
            comparisons++;
            int temp = pair[0];
            pair[0] = pair[i + 1];
            pair[1] = temp;
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

std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = a + 2 * temp;
    }
    return sequence;
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
    std::sort(pairs.begin(), pairs.end(), comparefirstElement);
    fillChains(pairs, main, pend);
    std::vector<int> jacobsthalSeq = buildJacobsthalSequence(pend.size());
    for (int i = 0; i < pend.size(); i++) {
        int insertionIndex = jacobsthalSeq[i];
        if (jacobsthalSeq[i] < pend.size())
            main.insert(std::lower_bound(main.begin(), main.end(), pend[insertionIndex], lowerBoundCompare), pend[insertionIndex]);
        else
            main.insert(std::lower_bound(main.begin(), main.end(), pend[i], lowerBoundCompare), pend[i]);
    }
    if (straggler != -1)
        main.insert(std::lower_bound(main.begin(), main.end(), straggler, lowerBoundCompare), straggler);
    std::cout << main << std::endl;
}

int main() {
    int arr[] = {67, 23, 45, 12, 89, 56, 34, 78, 98, 21, 55, 87, 32, 9, 41, 76, 63, 18, 50, 27, 14};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    

    mergeInsertionSort(vec);
    std::cout << "Number of comparisons == " << comparisons << std::endl;
    return 0;
}