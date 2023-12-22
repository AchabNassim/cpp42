#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int n) : array(n) {
}

Span::Span(const Span& ref) : array(ref.array) {
}

Span::~Span() {
}

void Span::addNumber(int n) {
    
}