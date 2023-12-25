#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <exception>
#include <stdexcept>
#include <vector>

Span::Span() : currentIndex(0), size(INT_MAX) {
}

Span::Span(unsigned int n) : vec(n), currentIndex(0), size(n) {
}

Span::Span(const Span& ref) : vec(ref.vec), currentIndex(ref.currentIndex), size(ref.size) {
}

Span& Span::operator=(const Span& ref) {
    if (this == &ref)
        return (*this);
    vec = ref.vec;
    this->size = ref.size;
    this->currentIndex = ref.currentIndex;
    return (*this);
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

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (std::distance(begin, end) > size - currentIndex)
        throw std::out_of_range("Not enough space in Span");
    std::copy(begin, end, vec.begin() + currentIndex);
    currentIndex += std::distance(begin, end);
}


int Span::shortestSpan() {
    int shortestDistance = INT_MAX;
    int currentDistance;

    if (size <= 1)
        throw std::exception();
    std::sort(vec.begin(), vec.begin() + currentIndex);
    for (unsigned int i = 0; i < currentIndex - 1; i++) {
        currentDistance = vec[i + 1] - vec[i];
        if (shortestDistance > currentDistance)
            shortestDistance = currentDistance;
    }
    return (shortestDistance);
}

long Span::longestSpan() {
    if (size <= 1)
        throw std::exception();
    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.begin() + currentIndex);
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.begin() + currentIndex);
    if (min != vec.end() && max != vec.end()) {
        return (*max - *min);
    }
    return (0);
}

std::vector<int>::const_iterator Span::getBegin() const {
    return (this->vec.begin());
}

std::vector<int>::const_iterator Span::getEnd() const {
    return (this->vec.end());
}

std::vector<int>const& Span::getVector() const {
    return (this->vec);
}

void    Span::print() {
    for (std::vector<int>::const_iterator it = this->vec.begin(); it != this->vec.end(); it++) {
        std::cout << *it << std::endl;
    }
}
