#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string m_type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal& ref);
        WrongAnimal& operator=(WrongAnimal& ref);
        ~WrongAnimal();


        void    makeSound() const;
        std::string     getType() const;
};

#endif