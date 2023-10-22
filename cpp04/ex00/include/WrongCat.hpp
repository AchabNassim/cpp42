#ifndef WRONG_CAT
# define WRONG_CAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        
        void    makeSound() const;
};

#endif