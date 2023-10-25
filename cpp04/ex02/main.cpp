#include "include/WrongAnimal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/AAnimal.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"
#include "include/Dog.hpp"

int main()
{
    AAnimal *doggo = new Dog();
    std::cout << doggo->getType();
    delete doggo;
    return 0;
}