#include "Zombie.hpp"

int main () {
    const int HORDE_NUMBER = 15;
    Zombie *Zombies = zombieHorde(HORDE_NUMBER, "Dummy");

    for (int i = 0; i < HORDE_NUMBER; i++) {
        Zombies[i].announce();
    }
    delete[] Zombies;
    return (0);
}