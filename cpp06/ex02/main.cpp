#include "inc/Base.hpp"
#include "inc/A.hpp"
#include "inc/B.hpp"
#include "inc/C.hpp"

int main () {
    Base base;
    Base* pt = base.generate();
    base.identify(pt);
    base.identify(*pt);
    delete pt;
    return (0);
}