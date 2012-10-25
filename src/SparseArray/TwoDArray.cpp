#include "TwoDArray.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
    assert(r > 0);
    assert(c > 0);
    rows = r;
    cols = c;
    def_value = def;

    for (int i = 0; i < rows; ++i) {
        vector<T> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(def_value);
        }
        array.push_back(row);
    }
}

template <typename T>
TwoDArray<T>::~TwoDArray() {
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
    assert(r >= 0 && r < rows);
    assert(c >= 0 && c < cols);

    array[r][c] = value;

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
    assert(r >= 0 && r < rows);
    assert(c >= 0 && c < cols);

    array[r][c] = def_value;

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
template class TwoDArray<string>;
