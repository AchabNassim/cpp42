#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public :
        MutantStack() {};
        MutantStack(const MutantStack& ref) : std::stack<T, Container>(ref) {}
        MutantStack& operator=(const MutantStack& ref) {
            if (this == &ref)
                return (*this);
            this->c = ref.c;
            return (*this);
        }
        ~MutantStack() {}
        typedef typename Container::iterator iterator;
        const iterator begin() const {
            return (this->c.begin());
        }
        const iterator end() const {
            return (this->c.end());
        }
        iterator begin() {
            return (this->c.begin());
        }
        iterator end() {
            return (this->c.end());
        }
};
