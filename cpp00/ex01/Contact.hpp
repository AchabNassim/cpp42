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
        int         index;

    public:
        void add () {
            std::string buffer = "";

            while (1)
            {
                std::cout << "\t*Please enter your first name: *" << std::endl;
                std::getline(std::cin, buffer);
                if (!buffer.empty() || buffer.length() != 0) {
                    this->firstName = buffer;
                    break ;
                }
                std::cout << "*Please enter a value!*" << std::endl;
            }
            while (1)
            {
                std::cout << "\t*Please enter your last name: *" << std::endl;
                std::getline(std::cin, buffer);
                if (!buffer.empty() || buffer.length() != 0) {
                    this->lastName = buffer;
                    break ;
                }
                std::cout << "*Please enter a value!*" << std::endl;
            }
            while (1)
            {
                std::cout << "\t*Please enter your nickname: *" << std::endl;
                std::getline(std::cin, buffer);
                if (!buffer.empty() || buffer.length() != 0) {
                    this->nickName = buffer;
                    break ;
                }
                std::cout << "*Please enter a value!*" << std::endl;
            }
            while (1)
            {
                std::cout << "\t*Please enter your phone number: *" << std::endl;
                std::getline(std::cin, buffer);
                if (!buffer.empty() || buffer.length() != 0) {
                    this->phoneNumber = buffer;
                    break ;
                }
                std::cout << "*Please enter a value!*" << std::endl;
            }
            while (1)
            {
                std::cout << "\t*Please enter your darkest secret: *" << std::endl;
                std::getline(std::cin, buffer);
                if (!buffer.empty() || buffer.length() != 0) {
                    this->darkestSecret = buffer;
                    break ;
                }
                std::cout << "*Please enter a value!*" << std::endl;
            }
        }
        std::string getFirstName() {
            return firstName;
        }
        std::string getLastName() {
            return lastName;
        }
        std::string getNickName() {
            return nickName;
        }
        std::string getPhoneNumber() {
            return phoneNumber;
        }
        std::string getDarkestSecret() {
            return darkestSecret;
        }
};

#endif