#include <iostream>

int main () {
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "Memory address of str is " << &str << std::endl;
    std::cout << "Memory address held by ptr " << ptr << std::endl;
    std::cout << "Memory address held by ref " << &ref << std::endl;

    std::cout << "Value of str is " << str << std::endl;
    std::cout << "Value held by ptr " << *ptr << std::endl;
    std::cout << "Value held by ref " << ref << std::endl;
}