#include "TwoDArray.h"
#include "Node.h"
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
    numRows = r;
    numCols = c;
    def_value = def;

    rows = new vector< Node<T>* >;
    for (int i = 0; i < numRows; ++i) {
        rows->push_back(0);
    }

    cols = new vector< Node<T>* >;
    for (int i = 0; i < numCols; ++i) {
        cols->push_back(0);
    }
}

template <typename T>
TwoDArray<T>::~TwoDArray() {
    for (int i = 0; i < numRows; ++i) {
        if ((*rows)[i] != 0) {
            deleteRow((*rows)[i]);
        }
    }
    for (int i = 0; i < numRows; ++i) {
        (*rows)[i] = 0;
    }
    for (int i = 0; i < numCols; ++i) {
        (*cols)[i] = 0;
    }
}

template <typename T>
void TwoDArray<T>::deleteRow(Node<T>* node) {
    if (node->getRight() != 0) {
        deleteRow(node->getRight());
    }

    delete node;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
    assert(r >= 0 && r < numRows);
    assert(c >= 0 && c < numCols);

    if (value == def_value) return;

    // find row node before insert
    Node<T>** rowCur = &(*rows)[r];
    while ( *rowCur != 0 && (*rowCur)->getCol() < c ) {
        Node<T>* temp = (*rowCur)->getRight();
        rowCur = &temp;
    }
    // get row node after insert
    Node<T>* nextRight = 0;
    if ((*rowCur) != 0) {
        nextRight = (*rowCur)->getRight();
    } 

    // find col node before insert
    Node<T>** colCur = &(*cols)[c];
    while ( *colCur != 0 && (*colCur)->getRow() < r) {
        Node<T>* temp = (*colCur)->getDown();
        colCur = &temp;
    }
    // get col node after insert
    Node<T>* nextDown = 0;
    if ((*colCur) != 0) {
        nextDown = (*colCur)->getDown();
    } 

    Node<T>* newNode = new Node<T>(r,c, value);
    newNode->setRight(nextRight);
    newNode->setDown(nextDown);

    if ((*rowCur) == 0) {
        (*rowCur) = newNode; 
    } else {
        (*rowCur)->setRight(newNode);
    }
    if ((*colCur) == 0) {
        (*colCur) = newNode;
    } else {
        (*colCur)->setDown(newNode);
    }

    return;   
}

template <typename T>
T TwoDArray<T>::access(int r, int c) {
    assert(r >= 0 && r < numRows);
    assert(c >= 0 && c < numCols);

    Node<T>** cur = &(*rows)[r];
    while ((*cur) != 0 && (*cur)->getCol() != c) {
        Node<T>* temp = (*cur)->getRight();
        cur = &temp;
    }
    if (*cur == 0) {
        return def_value;
    }

    return (*cur)->getValue();
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
    assert(r >= 0 && r < numRows);
    assert(c >= 0 && c < numCols);

    Node<T>** cur = &(*rows)[r];
    while ((*cur) != 0 && (*cur)->getCol() < c) {
        Node<T>* next = (*cur)->getRight();
        cur = &next;
    }
    // TODO: finish remove

    return;
}

template <typename T>
void TwoDArray<T>::print() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << access(i, j) << " ";
        }
        cout << endl;
    }
}

template <typename T>
int TwoDArray<T>::getNumRows() {
    return numRows;
}

template <typename T>
int TwoDArray<T>::getNumCols() {
    return numCols;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<string>;
