#include "../include/AMateria.hpp"
#include "../include/Character.hpp"

Character::Character() {
    std::cout << "Default constructor called\n";
    for (int i = 0; i < 4; i++) {
        this->m_slots[i] = NULL;
    }
    this->m_slotNumber = 0;
}

Character::Character(std::string const & name) {
    std::cout << "Character constructor called\n";
    this->m_name = name;
    for (int i = 0; i < 4; i++) {
        this->m_slots[i] = NULL;
    }
    this->m_slotNumber = 0;
}

Character::Character(Character &ref) {
    std::cout << "Character copy constructor called\n";
    this->m_name = ref.m_name;
    for (int i = 0; i < 4; i++) {
        this->m_slots[i] = ref.m_slots[i];
    }
    this->m_slotNumber = ref.m_slotNumber;
}

Character& Character::operator=(Character &ref) {
    std::cout << "Character assignement operator called\n";
    if (this == &ref)
        return (*this);
    this->m_name = ref.m_name;
    for (int i = 0; i < 4; i++) {
        this->m_slots[i] = ref.m_slots[i];
    }
    this->m_slotNumber = ref.m_slotNumber;
    return (*this);
}

Character::~Character() {
    std::cout << "Character destructor called\n";
    for (int i = 0; i < this->m_slotNumber; i++) {
        delete this->m_slots[i];
    }
}

std::string const & Character::getName() const {
    return (this->m_name);
}

void    Character::equip(AMateria *m) {
    if (this->m_slotNumber < 4) {
        this->m_slots[this->m_slotNumber] = m;
        this->m_slotNumber++;
    } else {
        std::cout << "All slots are full, try unequiping\n";
    }
}

void    Character::unequip(int idx) {
    if (idx < 4 && idx >= 0) {
        this->m_slots[this->m_slotNumber] = NULL;
        this->m_slotNumber--;
    } else {
        std::cout << "Slot requested is invalid\n";
    }
}

void    Character::use(int idx, ICharacter& target) {
    if (idx > this->m_slotNumber || idx < 0) {
        std::cout << "Slot requested is invalid\n";
    } else {
        this->m_slots[idx]->use(target);
    }
}