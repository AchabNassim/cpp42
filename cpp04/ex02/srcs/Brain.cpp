#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called\n";
}

Brain::Brain(Brain& ref) {
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = ref.ideas[i];
    }
}

Brain& Brain::operator=(Brain& ref) {
    std::cout << "Brain assignment operator called\n";
    if (this == &ref)
        return (*this);
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = ref.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called\n";
}

void    Brain::setIdea(int index, std::string idea) {
    this->ideas[index] = idea;
}

std::string    Brain::getIdea(int index) {
    return (this->ideas[index]);
}
