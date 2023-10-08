#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "myPhoneBook.hpp"

#define MAX_CONTACTS 8


class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int     emptyList;
        int     numberOfContacts;
        int     index;

        std::string trim(std::string str);
        void displayContactInfo (int index);

    public:
        PhoneBook();
        void addContact();
        void search ();
};

#endif
