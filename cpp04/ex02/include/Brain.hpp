#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain &ref);
        Brain& operator=(Brain &ref);
        ~Brain();

        void            setIdea(int index, std::string idea);
        std::string     getIdea(int index);
};

#endif