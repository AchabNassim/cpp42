#include "../include/MateriaSource.hpp"
#include "../include/AMateria.hpp"
#include "../include/Dump.hpp"

MateriaSource::MateriaSource() {
    // std::cout << "Default constructor called\n";
    for (int i = 0; i < 4; i++) {
        this->m_slots[i] = NULL;
    }
    this->m_slotNumber = 0;
}

MateriaSource::MateriaSource(MateriaSource &ref) {
    // std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < 4; i++) {
        if (this->m_slots[i] != NULL) {
            AMateria::StaticDump.setDump(this->m_slots[i]);
        }
        if (ref.m_slots[i] != NULL) {
            this->m_slots[i] = ref.m_slots[i]->clone();
        } else {
            this->m_slots[i] = NULL;
        }
    }
    this->m_slotNumber = ref.m_slotNumber;
}

MateriaSource& MateriaSource::operator=(MateriaSource &ref) {
    // std::cout << "MateriaSource assignement operator called\n";
    if (this == &ref)
        return (*this);
    for (int i = 0; i < 4; i++) {
        if (this->m_slots[i] != NULL) {
            AMateria::StaticDump.setDump(this->m_slots[i]);
        }
        if (ref.m_slots[i] != NULL) {
            this->m_slots[i] = ref.m_slots[i]->clone();
        } else {
            this->m_slots[i] = NULL;
        }
    }
    this->m_slotNumber = ref.m_slotNumber;
    return (*this);
}

MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource destructor called\n";
    for (int i = 0; i < this->m_slotNumber; i++) {
        delete this->m_slots[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (this->m_slotNumber < 4) {
        this->m_slots[m_slotNumber] = m;
        this->m_slotNumber++;
    } else {
        std::cout << "All slots are full, try unequiping\n";
        AMateria::StaticDump.setDump(m);
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->m_slots[i] && this->m_slots[i]->getType().compare(type) == 0) {
            return (this->m_slots[i]->clone());
        }
    }
    return (0);  
}