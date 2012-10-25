#include "TwoDArray.h"
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
    rows = r;
    cols = c;
    def_value = def;

    array = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new T[cols];
        for (int j = 0; j < cols; ++j) {
            array[i][j] = def_value;
        }
    }
}

template <typename T>
TwoDArray<T>::~TwoDArray() {
    for (int i = 0; i < rows; ++i) {
        delete array[i];
    }
    delete array;
}

template <typename T>
void TwoDArray<T>::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

template class TwoDArray<int>;
template class TwoDArray<double>;
