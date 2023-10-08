#include "PhoneBook.hpp"

int main(){
    PhoneBook   MyPhoneBook;
    std::string buffer;

    std::cout << "Welcome to Phonebook, in this program you can store up to 8 contacts! to start, please enter a command\n"
        << "\t** ADD: to add a new contact\n" 
        << "\t** SEARCH: to display and search for a specific contact\n" 
        << "\t** EXIT: to exit the program (Contacts will be lost forever)" << std::endl;
    while (1) {
        std::cout << "Enter a command : (ADD - SEARCH - EXIT)" << std::endl;
        if (!std::getline(std::cin, buffer)) {
            break ;
        }
        else if (buffer.compare("ADD") == 0) {
            MyPhoneBook.addContact();
        } else if (buffer.compare("SEARCH") == 0) {
            MyPhoneBook.search();
        } else if (buffer.compare("EXIT") == 0) {
            break ;
        }
    }
    std::cout << "Exiting the program, till the next time!" << std::endl;
    return (0);
}