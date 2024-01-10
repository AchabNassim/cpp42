#include <stack>
#include <iostream>
#include <algorithm>

class Rpn {
    private:
        std::stack<int> stack;
    public:
        Rpn();
        Rpn(const Rpn& ref);
        Rpn& operator=(const Rpn& ref);
        ~Rpn();
        void    addElement(char c);
        std::stack<int>& getStack();
};

std::ostream& operator<<(std::ostream& os, std::stack<int> stack);