#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

class Rpn {
    private:
        std::stack<int> stack;
    public:
        Rpn(const std::string fileName);
        Rpn(const Rpn& ref);
        Rpn& operator=(const Rpn& ref);
        ~Rpn();
        void    addElement(char c);
        std::stack<int>& getStack();
};

std::ostream& operator<<(std::ostream& os, std::stack<int> stack);