#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

typedef std::vector<int> vec;
std::ostream& operator<<(std::ostream &os, vec vector);
int comparisons;

int binarySearch(const vec& arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            comparisons++;
            return mid;
        }
        else if (arr[mid] < key) {
            comparisons++;
            low = mid + 1;
        }
        else {
            comparisons++;
            high = mid - 1;
        }
    }

    return low;
}

void binaryInsertionSort(vec& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find the correct position for the key using binary search
        int pos = binarySearch(arr, 0, j, key);

        // Shift elements to the right to make space for the key
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at its correct position
        arr[j + 1] = key;
    }
}

void binarySearchInsertion(vec& mainChain, int b) {
    int low = 0;
    int high = mainChain.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mainChain[mid] < b) {
            comparisons++;
            low = mid + 1;
        } else {
            comparisons++;
            high = mid - 1;
        }
    }
    mainChain.insert(mainChain.begin() + low, b);
}



void sortA(vec &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            int temp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = temp;
            comparisons++;
        }
    }
}

vec mergeSort(vec vector) {
    std::vector<vec> pairs;
    vec mainChain;
    vec pend;
    for (int i = 0; i < vector.size(); i += 2) {
        vec pair;
        pair.push_back(vector[i]);
        if (i + 1 < vector.size()) {
            pair.push_back(vector[i + 1]);
        }
        sortA(pair);
        pairs.push_back(pair);
    }
    for (int i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i][0]);
        if (pairs.size() > 1) {
            pend.push_back(pairs[i][1]);
        } else {
            pend.push_back(pairs[i][0]);
        }
    }
    binaryInsertionSort(mainChain);
    while (pend.size() > 0) {
        binarySearchInsertion(mainChain, pend[0]);
        pend.erase(pend.begin());
    }
    for (int i = 0; i < pairs.size(); i++) {
        std::cout << pairs[i] << std::endl;
    }
    std::cout << mainChain << std::endl;
    return (vector);
}


int main() {
    int arr[] = {4,1,8,5,3,12,2,11,13,15,14,80,52,54,71,9,17,47,42,35,1};
    vec vector(arr, arr + sizeof(arr) / sizeof(arr[0]));
    mergeSort(vector);
    std::cout << "sorted in " << comparisons << std::endl;
    return (0);
}

std::ostream& operator<<(std::ostream &os, vec vector) {
    for (vec::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << std::endl;
    }
    return (os);
}