#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 3 + 1;
    switch (randomNumber) {
        case 1:
            return (new A);
        case 2:
            return (new B);
        case 3:
            return (new C);
    }
    return (NULL);
}