#include "Rpn.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &ref) {
    this->stack = ref.stack;
}

Rpn::~Rpn() {}

Rpn& Rpn::operator=(const Rpn &ref) {
    this->stack = ref.stack;
    return (*this);
}

std::stack<char>& Rpn::getStack() {
    return (this->stack);
}

int    operation(int n1, int n2, char op) {
    if (op == '+')
        return (n1 + n2);
    else if (op == '-')
        return (n1 - n2);
    else if (op == '*')
        return (n1 * n2);
    else if (op == '/')
        return (n1 / n2);
    return (0);
}

void    Rpn::addElement(char currentCell) {
    std::stack<char>& stack = this->getStack();
    int             currentNb = 0;
    static int      oper = 0;
    int             previousNb = 0;

    if (currentCell == '+' || currentCell == '-' || currentCell == '*' || currentCell == '/') {
        oper += 1;
        if (oper > 1) {
            std::cerr << "Error: please enter a valid number of operators" << std::endl;
            return ;
        }
        if (stack.size() > 2) {
            currentNb = stack.top() - 48;
            stack.pop();
            previousNb = stack.top() - 48;
            stack.pop();
            stack.push(operation(previousNb, currentNb, currentCell));
            std::cout << stack.top() << std::endl;
            oper--;
        } 
    } else if (isdigit(currentCell)) {
        stack.push(currentCell);
    } else {
        std::cerr << "Error: invalid reverse polish notation" << std::endl;
        exit (1);
    }
}