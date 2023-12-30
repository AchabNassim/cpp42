#include "Span.hpp"
#include <climits>
#include <exception>
#include <stdexcept>

Span::Span() : currentIndex(0), size(INT_MAX) {
}

Span::Span(unsigned int n) : currentIndex(0), size(n) {
}

Span::Span(const Span& ref) : container(ref.container), currentIndex(ref.currentIndex), size(ref.size) {
}

Span& Span::operator=(const Span& ref) {
    if (this == &ref)
        return (*this);
    container = ref.container;
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
        container.push_back(n);
        currentIndex++;
    }
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) {
    if (std::distance(begin, end) > size - currentIndex)
        throw std::out_of_range("index not valid");
    else {
        container.assign(begin, end);
        currentIndex += std::distance(begin, end);
    }
}



int Span::shortestSpan() {
    if (currentIndex <= 1) {
        throw std::out_of_range("index not valid");
    }
    std::list<int> sortedList(container.begin(), container.end());
    int currentDistance;
    int shortestDistance = INT_MAX;
    sortedList.sort();
    for (std::list<int>::iterator node = sortedList.begin(); node != sortedList.end(); node++) {
        std::list<int>::iterator nextNode = node;
        ++nextNode;
        if (nextNode != sortedList.end()) {
            currentDistance = *nextNode - *node;
            if (shortestDistance > currentDistance)
                shortestDistance = currentDistance;
        }
    }
    return (shortestDistance);
}

long Span::longestSpan() {
    if (currentIndex <= 1)
        throw std::out_of_range("index not valid");
    std::list<int>::iterator min = std::min_element(container.begin(), container.end());
    std::list<int>::iterator max = std::max_element(container.begin(), container.end());
    return (*max - *min);
}

std::list<int>::const_iterator Span::getBegin() const {
    return (container.begin());
}

std::list<int>::const_iterator Span::getEnd() const {
    return (container.end());
}

std::list<int>const& Span::getList() const {
    return (this->container);
}

// void    Span::print() {
//     for (std::list<int>::iterator it = container.begin(); it != container.end(); it++) {
//         std::cout << *it << std::endl;
//     }
// }

std::ostream& operator<<(std::ostream &os, const Span &ref) {
    for (std::list<int>::const_iterator it = ref.getBegin(); it != ref.getEnd(); it++) {
        os << *it << std::endl;
    }
    return (os);
}
