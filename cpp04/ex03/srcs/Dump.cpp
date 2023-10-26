#include "../include/Dump.hpp"
#include "../include/AMateria.hpp"
#include <climits>

Dump::Dump() {
    // std::cout << "Constructor called\n";
    for (int i = 0; i < SHRT_MAX; i++) {
        this->materias[i] = NULL;
    }
    this->index = 0;
}

Dump::Dump(Dump &ref) {
    // std::cout << "Copy constructor called\n";
    for (int i = 0; i < SHRT_MAX; i++) {
        this->materias[i] = ref.materias[i];
    }
    this->index = ref.index;
}

Dump& Dump::operator=(Dump &ref) {
    // std::cout << "Assignement operator called\n";
    if (this == &ref) {
        return (*this);
    }
    for (int i = 0; i < SHRT_MAX; i++) {
        this->materias[i] = ref.materias[i];
    }
    this->index = ref.index;
    return (*this);
}

Dump::~Dump() {
    // std::cout << "Destructor called\n";
    for (int i = 0; i < SHRT_MAX; i++) {
        if (this->materias[i] != NULL) {
            std::cout << "Freed materia at address " << this->materias[i] << std::endl;
            delete this->materias[i];
        }
    }
}

void    Dump::setDump(AMateria *m) {
    this->materias[index] = m;
    this->index = index + 1;
}
