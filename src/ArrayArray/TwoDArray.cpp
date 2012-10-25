#include "TwoDArray.h"
#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
    assert(r > 0);
    assert(c > 0);

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
void TwoDArray<T>::insert(int r, int c, T value) {
    assert(r == r);
    assert(c == c);
    assert(value == value);
    return;   
}

template <typename T>
T TwoDArray<T>::access(int r, int c) {
    assert(r >= 0 && r < rows);
    assert(c >= 0 && c < cols);

    return array[r][c];
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
    assert(r == r);
    assert(c == c);
    return;
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

template <typename T>
int TwoDArray<T>::getNumRows() {
    return rows;
}

template <typename T>
int TwoDArray<T>::getNumCols() {
    return cols;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
