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
    return (first[0] < second[0]);
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
            main.push_back(pairs[i][0]);
            pend.push_back(pairs[i][1]);
        } else {
            pend.push_back(pairs[i][0]);
        }
    }
}

// Function to implement the Merge Insertion Sort algorithm
void mergeInsertionSort(std::vector<int>& vec) {
    std::vector<std::vector<int> > pairs;
    std::vector<int> main;
    std::vector<int> pend;
    
    makePairs(pairs, vec);
    std::sort(pairs.begin(), pairs.end(), comparefirstElement);
    fillChains(pairs, main, pend);
    for (int i = 0; i < pend.size(); i++) {
        main.insert(std::lower_bound(main.begin(), main.end(), pend[i], lowerBoundCompare), pend[i]);
    }
    std::cout << main << std::endl;
}

int main() {
    int arr[] = {67, 23, 45, 12, 89, 56, 34, 78, 98, 21, 55, 87, 32, 9, 41, 76, 63, 18, 50, 27, 14};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    

    mergeInsertionSort(vec);
    std::cout << "Number of comparisons == " << comparisons << std::endl;
    return 0;
}