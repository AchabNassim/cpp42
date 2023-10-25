#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain* brain;
    public:
        Dog();
        Dog(Dog &ref);
        Dog& operator=(Dog &ref);
        ~Dog();

        void    makeSound() const;
};

#endif