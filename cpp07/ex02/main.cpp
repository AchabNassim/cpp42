#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main() {
    Array<std::string> strArr(3);
    strArr[0] = "Hey";
    strArr[1] = "it's";
    strArr[2] = "working";
    // strArr[3] = "working";
    std::cout << "**** string array ****\n";
    strArr.display();
    Array<int> intArr(3);
    intArr[0] = 1;
    intArr[1] = 2;
    intArr[2] = 3;
    std::cout << "**** int array ****\n";
    intArr.display();
    Array<float> floatArr;
    std::cout << "**** empty float array ****\n";
    floatArr.display();
    Array<std::string> strCopyArray(2);
    strCopyArray[0] = "Copy";
    strCopyArray[1] = "Successfull";
    strArr = strCopyArray;
    std::cout << "**** copied string array ****\n";
    strArr.display();
    strArr[0] = "Modification";
    std::cout << "**** Modified string array ****\n";
    strArr.display();
    std::cout << "**** Copy string array ****\n";
    strCopyArray.display();
    // while (1);
}