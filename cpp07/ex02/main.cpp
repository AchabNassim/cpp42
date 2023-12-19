#include "Array.hpp"

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