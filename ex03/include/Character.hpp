#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class   Character : public ICharacter {
    private:
        std::string m_name;
        AMateria*   m_slots[4];
        int         m_slotNumber;
    public:
        Character();
        Character(std::string const &name);
        Character(Character &ref);
        Character& operator=(Character &ref);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif