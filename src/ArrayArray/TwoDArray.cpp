#include "TwoDArray.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
    array = new T*[r];
    for (int i = 0; i < r; ++i) {
        array[i] = new T[c];
        for (int j = 0; j < c; ++j) {
            array[i][j] = def;
        }
    }
}

template <typename T>
TwoDArray<T>::~TwoDArray() {



template class TwoDArray<int>;
template class TwoDArray<double>;
