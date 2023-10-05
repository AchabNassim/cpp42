#include "MyPhoneBook.hpp"

int main(){
    PhoneBook   myPhoneBook;
    std::string buffer;

    std::cout << "Welcome to Phonebook, in this program you can store up to 8 contacts! to start, please enter a command\n"
        << "ADD: to add a new contact\n" 
        << "SEARCH: to display and search for a specific contact\n" 
        << "EXIT: to exit the program (Contacts will be lost forever)" << std::endl;
    while (1) {
        std::cout << "Enter a command : (ADD - SEARCH - EXIT)" << std::endl;
        if (!std::getline(std::cin, buffer)) {
            break ;
        }
        else if (buffer.compare("ADD") == 0) {
            myPhoneBook.addContact();
        } else if (buffer.compare("SEARCH") == 0) {
            myPhoneBook.search();
        } else if (buffer.compare("EXIT") == 0) {
            break ;
        }
    }
    std::cout << "Exiting the program, till the next time!" << std::endl;
    return (0);
}