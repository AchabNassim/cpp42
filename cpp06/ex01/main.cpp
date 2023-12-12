#include "Serializer.hpp"
#include "Data.hpp"
#include <sys/_types/_uintptr_t.h>

int main() {
    Data dummy;
    uintptr_t pt;
    pt = Serializer::serialize(&dummy);
    if (&dummy != Serializer::deserialize(pt))
        std::cerr << "Address does not match" << std::endl;
    else
        std::cout << "Address matches! &data == " << &dummy << " uintptr_t address == " << Serializer::deserialize(pt) << std::endl;;
    return (0);
}