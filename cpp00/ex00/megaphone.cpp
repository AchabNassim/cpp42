#include <iostream>

int main(int ac, char **av) {
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; av[i][j] != '\0'; j++) {
                char c = av[i][j];
                if (isalpha(c) && islower(c)) {
                    c = toupper(c);
                }
                std::cout << c;
            }
        }
    }
    std::cout << std::endl;
    return (0);
}