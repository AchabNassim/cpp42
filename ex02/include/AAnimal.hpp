#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string m_type;
        AAnimal();
        AAnimal(std::string type);
        AAnimal(AAnimal& ref);
        AAnimal& operator=(AAnimal& ref);
    public:
        virtual ~AAnimal();

        virtual void    makeSound() const = 0;
        std::string     getType() const;
};

#endif