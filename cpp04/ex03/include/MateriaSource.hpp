#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria*   m_slots[4];
        int         m_slotNumber;
    public:
        MateriaSource();
        MateriaSource(std::string const &name);
        MateriaSource(MateriaSource &ref);
        MateriaSource& operator=(MateriaSource &ref);
        ~MateriaSource();
        
        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
};

#endif