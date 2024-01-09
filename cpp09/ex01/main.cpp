#include <_ctype.h>
#include <stack>
#include <algorithm>
#include <iostream>

void    fillRequestedOperator(int* arr, char op) {
    std::fill(arr, arr + 4, 0);
    if (op == '+')
        arr[0] = 1;
    else if (op == '-')
        arr[1] = 1;
    else if (op == '*')
        arr[2] = 1;
    else if (op == '/')
        arr[3] = 1;
}

void    makeCalculation(int *arr, int numb, int &total) {
    if (arr[0] == 1) {
        total = numb + total;
    } else if (arr[1] == 1) {
        total = numb - total;
    } else if (arr[2] == 1) {
        total = numb * total;
    } else if (arr[3] == 1) {
        total = numb / total;
    }
    // std::cout << "Numb == " << numb << std::endl;
    // std::cout << "Total after calculation == " << total << std::endl;
}

void    calculate(std::stack<char> stack) {
    char    currentCell;
    int     requestedop[4] = {0, 0, 0, 0};
    int     oper = 0;
    int     total = 0;
    int     currentNb;

    if (stack.empty())
        return ;
    while (!stack.empty()) {
        currentCell = stack.top();
        stack.pop();
        if (currentCell == '+' || currentCell == '-' || currentCell == '*' || currentCell == '/') {
            oper = 1;
            fillRequestedOperator(requestedop, currentCell);
        } else if (isdigit(currentCell)) {
            currentNb = currentCell - 48;
            if (total == 0) {
                total = currentNb;
            } else {
                makeCalculation(requestedop, currentNb, total);
            }
        } else {
            std::cerr << "Error: Invalid rpn" << std::endl;
        }
    }
    std::cout << total << std::endl;
}

int main() {
    std::stack<char> stack;
    stack.push('7');
    stack.push('+');
    stack.push('5');
    stack.push('7');
    stack.push('-');
    calculate(stack);
}