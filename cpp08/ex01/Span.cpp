#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <exception>
#include <stdexcept>
#include <vector>

Span::Span() : size(0), currentIndex(0) {
}

Span::Span(unsigned int n) : vec(n), size(n), currentIndex(0) {
}

Span::Span(const Span& ref) : vec(ref.vec) {
}

Span::~Span() {
}

void Span::addNumber(int n) {
    if (currentIndex >= size)
        throw std::out_of_range("index not valid");
    else {
        vec[currentIndex] = n;
        currentIndex++;
    }
}


int Span::shortestSpan() {
    int shortestDistance = INT_MAX;
    int currentDistance;

    if (size <= 1)
        throw std::exception();
    std::sort(vec.begin(), vec.begin() + currentIndex);
    for (int i = 0; i < currentIndex - 1; i++) {
        currentDistance = vec[i + 1] - vec[i];
        if (shortestDistance > currentDistance)
            shortestDistance = currentDistance;
    }
    return (shortestDistance);
}

long Span::longestSpan() {
    int longestDistance = 0;
    int currentDistance;

    if (size <= 1)
        throw std::exception();
    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.begin() + currentIndex);
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.begin() + currentIndex);
    if (min != vec.end() && max != vec.end()) {
        return (*max - *min);
    }
    return (0);
}