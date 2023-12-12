#pragma once

#include <iostream>

class Data {
    private:
        std::string name;
    public:
        Data();
        Data(Data &ref);
        Data& operator=(Data &ref);
        ~Data();
};