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

std::stack<int>& Rpn::getStack() {
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
    std::stack<int>&        stack = this->getStack();
    static int              oper = 0;
    static int              foundOp = 0;
    int                     currentNb = 0;
    int                     previousNb = 0;

    if (currentCell == '+' || currentCell == '-' || currentCell == '*' || currentCell == '/') {
        // std::cout << "operator is == " << currentCell << std::endl;
        oper += 1;
        foundOp++;
        if (oper > 1) {
            std::cerr << "Error: please enter a valid number of operators" << std::endl;
            return ;
        }
        // std::cout << "stack size == " << stack.size() << std::endl;
        if (stack.size() >= 2) {
            // std::cout << "stack size > 2\n";
            currentNb = stack.top();
            stack.pop();
            previousNb = stack.top();
            stack.pop();
            // std::cout << operation(previousNb, currentNb, currentCell) << std::endl;
            stack.push(operation(previousNb, currentNb, currentCell));
            oper--;
        } 
    } else if (isdigit(currentCell)) {
        if (foundOp > 0) {
            std::cerr << "Error: invalid reverse polish notation" << std::endl;
            exit (1);
        }
        stack.push(currentCell - 48);
        // std::cout << stack.top() << std::endl;
    } else {
        std::cerr << "Error: invalid reverse polish notation" << std::endl;
        exit (1);
    }
}

std::ostream& operator<<(std::ostream& os, std::stack<int> stack) {
    while (!stack.empty()) {
        os << "Value stored in stack == " << stack.top() << std::endl;
        stack.pop();
    }
    return (os);
}