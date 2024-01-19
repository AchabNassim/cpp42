#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

typedef std::vector<int> vec;

vec concatVectors(vec mainVector, vec left, vec right) {
    for (vec::iterator it = left.begin(); it != left.end(); it++) {
        mainVector.push_back(*it);
    }
    for (vec::iterator it = right.begin(); it != right.end(); it++) {
        mainVector.push_back(*it);
    }
    return (mainVector);
}

vec slice(vec vector, int start, int end = 0) {
    vec sub;
    if (end == 0) {
        end = vector.size();
    }
    vec::iterator it = vector.begin();
    std::advance(it, start);
    while (it != vector.end() && start < end) {
        sub.push_back(*it);
        start++;
        it++;
    }
    return (sub);
}

vec merge(vec left, vec right) {
    vec vector;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            vector.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            vector.push_back(right[rightIndex]);
            rightIndex++;
        }
    }
    return (concatVectors(vector, slice(left, leftIndex), slice(right, rightIndex)));
}

vec mergeSort(vec vector) {
    if (vector.size() <= 1) {
        return (vector);
    }
    int mid = floor(vector.size() / 2);
    vec left = slice(vector,0, mid);
    vec right = slice(vector, mid, vector.size());

    vec sortedLeft = mergeSort(left);
    vec sortedRight = mergeSort(right);
    return (merge(sortedLeft, sortedRight));
}

std::ostream& operator<<(std::ostream &os, vec vector) {
    for (vec::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << std::endl;
    }
    return (os);
}

int main() {
    int arr[] = {4,1,8,5,3,12,2,15};
    vec vector(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << mergeSort(vector) << std::endl;
    return (0);
}