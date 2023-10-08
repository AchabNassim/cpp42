#include "Zombie.hpp"

int main () {
    std::string buffer;

    std::cout << "Creating a zombie on the stack, please provide a name for it" << std::endl;
    if (!std::getline(std::cin, buffer))
        return (0);
    Zombie StackZombie(buffer);
    StackZombie.announce();

    std::cout << "Creating a zombie on the heap, please provide a name for it" << std::endl;
    if (!std::getline(std::cin, buffer))
        return (0);
    Zombie *HeapZombie = newZombie(buffer);
    HeapZombie->announce();
    delete HeapZombie;

    std::cout << "Creating a random zombie" << std::endl;
    randomChump("Dummy");
    return (0);
}