#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
class   ICharacter;
class   Dump;

class AMateria
{
    protected:
        std::string m_type;
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria &ref);
    public:
        static Dump StaticDump;
        virtual ~AMateria();
        AMateria& operator=(AMateria &ref);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif