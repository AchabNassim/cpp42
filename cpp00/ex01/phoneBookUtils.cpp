#include "myPhoneBook.hpp"

// private functions of the class

std::string PhoneBook::trim(std::string str) {
    if (str.length() > 10) {
        return (str.substr(0, 9) + ".");
    } else {
        return (str);
    }
}

void PhoneBook::displayContactInfo (int index) {
    std::cout << "\033[32mRequested contact at index :" << index << "\033[0m" << "\n"
        << "Contact first name : " << contacts[index - 1].getFirstName() << "\n"
        << "Contact last name : " << contacts[index - 1].getLastName() << "\n"
        << "Contact  nickname : " << contacts[index - 1].getNickName() << "\n"
        << "Contact phone number : " << contacts[index - 1].getPhoneNumber() << "\n"
        << "Contact darkest secret : " << contacts[index - 1].getDarkestSecret() << "\n"
        ;
}

//public functions of the class

PhoneBook::PhoneBook() {
    index = 0;
    emptyList = 1;
    numberOfContacts = 0;
}

void PhoneBook::addContact() {
    if (index >= 8) {
        std::cout << "\033[31m~Contact list is full, gonna overwrite the oldest one!~\033[0m" << std::endl;
        index = 0;
    }
    contacts[index].add();
    std::cout << "\033[32mcontact saved in [" << index + 1 << "] spot.\033[0m" << std::endl;
    index++;
    emptyList = 0;
    if (numberOfContacts != 8)
        numberOfContacts++;
}

void PhoneBook::search () {
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
    if (std::cin.eof())
        exit(0) ;
    if (std::cin.fail()) {
        std::cout << "\033[31mInput entered was not valid, search aborted.\n\033[0m";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (index <= 0 || index > numberOfContacts) {
            std::cout << "\033[31mNumber entered was not valid (only 1-8 accepted), search aborted.\n\033[0m";
            return ;
        }
        displayContactInfo(index);
    }
}