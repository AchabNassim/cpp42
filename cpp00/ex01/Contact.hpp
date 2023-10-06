#ifndef CONTACT_HPP
# define CONTACT_HPP

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

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        void        add();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

#endif