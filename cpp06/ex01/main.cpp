#include "Serializer.hpp"
#include "Data.hpp"
#include <sys/types.h>
// #include <sys/_types/_uintptr_t.h>

int main() {
    Data        dummy;
    uintptr_t   ptr1;
    Data        *ptr2;
    ptr1 = Serializer::serialize(&dummy);
    ptr2 = Serializer::deserialize(ptr1);
    if (&dummy != ptr2)
        std::cerr << "Address does not match" << std::endl;
    else
    {
        std::cout << "Address matches! &data == " << &dummy << " uintptr_t address == " << ptr2 << std::endl;
        std::cout << "Name of data using deserialized pointer == " << ptr2->getName() << std::endl;
    }
    return (0);
}