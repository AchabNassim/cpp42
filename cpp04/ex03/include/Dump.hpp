#ifndef DUMP_HPP
# define DUMP_HPP

#include <climits>
class AMateria;

class Dump {
    private:
        AMateria*   materias[SHRT_MAX];
        int         index;
    public:
        Dump();
        Dump(Dump &ref);
        Dump& operator=(Dump &ref);
        ~Dump();

        void    setDump(AMateria *m);
};

#endif