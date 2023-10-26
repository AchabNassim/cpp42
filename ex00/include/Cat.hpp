#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(Cat &ref);
        Cat& operator=(Cat &ref);
        ~Cat();
        
        void    makeSound() const;
};

#endif