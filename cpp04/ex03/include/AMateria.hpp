#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
    protected:
        std::string type;
        AMateria();
    public:
        AMateria(std::string const & type);
        AMateria(AMateria &ref);
        virtual ~AMateria();
        AMateria& operator=(AMateria &ref);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);
};


#endif