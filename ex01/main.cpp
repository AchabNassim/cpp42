#include "include/WrongAnimal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"
#include "include/Dog.hpp"

int main()
{
    Animal *animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }
    return 0;
}