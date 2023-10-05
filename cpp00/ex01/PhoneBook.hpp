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

        std::string trim(std::string str) {
            if (str.length() > 10) {
                return (str.substr(0, 9) + ".");
            } else {
                return (str);
            }
        }

        void displayContactInfo (int index) {
            std::cout << "\033[32mRequested contact at index :" << index << "\033[0m" << "\n"
                << "Contact first name : " << contacts[index - 1].getFirstName() << "\n"
                << "Contact last name : " << contacts[index - 1].getLastName() << "\n"
                << "Contact  nickname : " << contacts[index - 1].getNickName() << "\n"
                << "Contact last name : " << contacts[index - 1].getPhoneNumber() << "\n"
                << "Contact last name : " << contacts[index - 1].getDarkestSecret() << "\n"
                ;
        }

    public:
        PhoneBook() {
            index = 0;
            emptyList = 1;
            numberOfContacts = 0;
        }
        void addContact() {
            if (index >= 8) {
                std::cout << "\033[31m~Contact list is full, gonna overwrite the oldest one!~" << "\033[0m" << std::endl;
                index = 0;
            }
            contacts[index].add();
            std::cout << "\033[32mcontact saved in [" << index + 1 << "] spot." << "\033[0m" << std::endl;
            index++;
            emptyList = 0;
            if (numberOfContacts != 8)
                numberOfContacts++;
        }
        void search () {
            if (emptyList) {
                std::cout << "\033[31mContact list is empty, please try again later.\n" << "\033[0m";
                return ;
            }
            std::string buffer;
            int         index;

            std::cout << " ___________________________________________ " << std::endl;
	        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	        std::cout << "|----------|----------|----------|----------|" << std::endl;
            for (int i = 0; i < numberOfContacts; i++) {
                std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << trim(contacts[i].getFirstName()) << "|" << std::setw(10) << trim(contacts[i].getLastName()) << "|" << std::setw(10) << trim(contacts[i].getNickName()) << "|" << std::endl;
            }
            std::cout << " ___________________________________________ " << std::endl;
            std::cout << "\033[32m*Please type the index of the number you want to see*" << "\033[0m" << std::endl;
            std::cin >> index;
            if (std::cin.fail()) {
                std::cout << "Input entered was not valid, search aborted.\n";
                return ;
            } else {
                if (index <= 0 || index > numberOfContacts) {
                    std::cout << "Number entered was not valid (only 1-8 accepted), search aborted.\n";
                    return ;
                }
                displayContactInfo(index);
            }
        }
};

#endif