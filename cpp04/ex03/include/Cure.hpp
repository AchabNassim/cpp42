#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

#define CLASSNAME "cure"

class Cure : public AMateria {
    public:
        Cure();
        Cure(Cure& ref);
        Cure& operator=(Cure& ref);
        ~Cure();

        AMateria*    clone() const;
        // void        use(Icharacter &target);
};

#endif