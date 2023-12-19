#pragma once
#include <iostream>
#include <stdexcept>
#include <sys/_types/_size_t.h>

template <typename T>
class Array {
    private:
        T*      array;
        size_t  _size;
    public:
        Array() : array(NULL), _size(0) {}
        Array(unsigned int n) {
            array = new T[n];
            _size = n;
        }
        Array(Array &ref) {
            if (ref.array != NULL) {
                delete[] this->array;
                this->array = new T[ref._size];
                this->_size = ref._size;
                for (size_t i = 0; i < ref._size; i++) {
                    this->array[i] = ref.array[i];
                }
            } else {
                delete[] this->array;
                this->array = NULL;
            }
        }
        Array& operator=(Array &ref) {
            if (ref.array != NULL) {
                delete[] this->array;
                this->array = new T[ref._size];
                this->_size = ref._size;
                for (size_t i = 0; i < ref._size; i++) {
                    this->array[i] = ref.array[i];
                }
            } else {
                delete[] this->array;
                this->array = NULL;
            }
            return (*this);
        }
        ~Array() {delete[] array ;}

        T& operator[](size_t index) {
            if (index < _size)
                return (this->array[index]);
            else {
                std::cerr << "Index requested isn't valid" << std::endl;
                throw std::out_of_range("Index requested isn't valid");
            }
        }
        size_t  size() { return _size; }
        void    display() {
            if (this->array != NULL) {
                for (size_t i = 0; i < _size; i++)
                    std::cout << array[i] << std::endl;
            } else {
                std::cerr << "Array is empty" << std::endl;
            }
        }
};