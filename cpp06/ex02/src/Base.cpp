#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <exception>

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

void    Base::identify(Base* p) {
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a != NULL)
        std::cout << "Object is of type A" << std::endl;
    else if (b != NULL)
        std::cout << "Object is of type B" << std::endl;
    else if (c != NULL)
        std::cout << "Object is of type C" << std::endl;
}


void    Base::identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Object is of type A" << std::endl;
        (void)a;
    } catch (std::bad_exception &e) {
    }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Object is of type B" << std::endl;
        (void)b;
    } catch (std::bad_exception &e) {
    }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Object is of type C" << std::endl;
        (void)c;
    } catch (std::bad_exception &e) {
    }
}