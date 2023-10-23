#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string m_type;
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal& ref);
        Animal& operator=(Animal& ref);
        ~Animal();


        virtual void    makeSound() const;
        std::string     getType() const;
};

#endif