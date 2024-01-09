#include <stack>
#include <iostream>
#include <algorithm>

class Rpn {
    private:
        std::stack<char> stack;
    public:
        Rpn();
        Rpn(const Rpn& ref);
        Rpn& operator=(const Rpn& ref);
        ~Rpn();
        void    addElement(char c);
        std::stack<char>& getStack();
};