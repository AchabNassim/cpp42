#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(Cat &ref);
        Cat& operator=(Cat &ref);
        ~Cat();
        
        void    makeSound() const;
};

#endif