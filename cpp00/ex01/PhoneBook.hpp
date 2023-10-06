#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#ifndef INCLUDES
# define INCLUDES
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#endif

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
