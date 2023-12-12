#include "Data.hpp"

Data::Data() : name("Random") {
}

Data::Data(Data &ref) {
    this->name = ref.name;
}

Data& Data::operator=(Data &ref) {
    if (this == &ref)
        return (*this);
    return (*this);
}

Data::~Data() {
}