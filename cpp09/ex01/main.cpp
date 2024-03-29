#include "Rpn.hpp"

// void    fillRequestedOperator(int* arr, char op) {
//     std::fill(arr, arr + 4, 0);
//     if (op == '+')
//         arr[0] = 1;
//     else if (op == '-')
//         arr[1] = 1;
//     else if (op == '*')
//         arr[2] = 1;
//     else if (op == '/')
//         arr[3] = 1;
// }

// void    makeCalculation(int *arr, int numb, int &total) {
//     if (arr[0] == 1) {
//         total = numb + total;
//     } else if (arr[1] == 1) {
//         total = numb - total;
//     } else if (arr[2] == 1) {
//         total = numb * total;
//     } else if (arr[3] == 1) {
//         total = numb / total;
//     }
// }

// void    calculate(std::stack<char> stack) {
//     char    currentCell;
//     int     requestedop[4] = {0, 0, 0, 0};
//     int     oper = 0;
//     int     total = 0;
//     int     currentNb;

//     if (stack.empty())
//         return ;
//     while (!stack.empty()) {
//         currentCell = stack.top();
//         stack.pop();
//         if (currentCell == '+' || currentCell == '-' || currentCell == '*' || currentCell == '/') {
//             oper += 1;
//             if (oper > 1) {
//                 std::cerr << "Error: please enter a valid number of operators" << std::endl;
//                 return ;
//             }
//             fillRequestedOperator(requestedop, currentCell);
//         } else if (isdigit(currentCell)) {
//             currentNb = currentCell - 48;
//             if (total == 0) {
//                 total = currentNb;
//             } else {
//                 makeCalculation(requestedop, currentNb, total);
//                 oper--;
//             }
//         } else {
//             std::cerr << "Error: Invalid rpn" << std::endl;
//         }
//     }
//     std::cout << total << std::endl;
// }

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Please enter a valid number of arguments" << std::endl;
        return (0);
    }
    Rpn rpn(av[1]);
    std::cout << rpn.getStack();
    return (0);
}