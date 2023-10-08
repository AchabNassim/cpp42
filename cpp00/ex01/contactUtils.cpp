#include "myPhoneBook.hpp"

void Contact::add () {
    std::string buffer;

    while (1)
    {
        std::cout << "*Please enter your first name: *" << std::endl;
        if(!std::getline(std::cin, buffer)) {
            std::cout << "Exiting the program, till the next time!" << std::endl;
            std::exit(0);
        }
        if (!buffer.empty() || buffer.length() != 0) {
            this->firstName = buffer;
            break ;
        }
        std::cout << "*Please enter a value!*" << std::endl;
    }
    while (1)
    {
        std::cout << "*Please enter your last name: *" << std::endl;
        if(!std::getline(std::cin, buffer)) {
            std::cout << "Exiting the program, till the next time!" << std::endl;
            std::exit(0);
        }
        if (!buffer.empty() || buffer.length() != 0) {
            this->lastName = buffer;
            break ;
        }
        std::cout << "*Please enter a value!*" << std::endl;
    }
    while (1)
    {
        std::cout << "*Please enter your nickname: *" << std::endl;
        if(!std::getline(std::cin, buffer)) {
            std::cout << "Exiting the program, till the next time!" << std::endl;
            std::exit(0);
        }
        if (!buffer.empty() || buffer.length() != 0) {
            this->nickName = buffer;
            break ;
        }
        std::cout << "*Please enter a value!*" << std::endl;
    }
    while (1)
    {
        std::cout << "*Please enter your phone number: *" << std::endl;
        if(!std::getline(std::cin, buffer)) {
            std::cout << "Exiting the program, till the next time!" << std::endl;
            std::exit(0);
        }
        if (!buffer.empty() || buffer.length() != 0) {
            this->phoneNumber = buffer;
            break ;
        }
        std::cout << "*Please enter a value!*" << std::endl;
    }
    while (1)
    {
        std::cout << "*Please enter your darkest secret: *" << std::endl;
        if(!std::getline(std::cin, buffer)) {
            std::cout << "Exiting the program, till the next time!" << std::endl;
            std::exit(0);
        }
        if (!buffer.empty() || buffer.length() != 0) {
            this->darkestSecret = buffer;
            break ;
        }
        std::cout << "*Please enter a value!*" << std::endl;
    }
}

std::string Contact::getFirstName() {
    return firstName;
}

std::string Contact::getLastName() {
    return lastName;
}

std::string Contact::getNickName() {
    return nickName;
}

std::string Contact::getPhoneNumber() {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() {
    return darkestSecret;
}