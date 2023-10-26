#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog &ref);
        Dog& operator=(Dog &ref);
        ~Dog();

        void    makeSound() const;
};

#endif