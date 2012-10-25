#include "Node.h"
#include <assert.h>
#include <string>
using std::string;

template <typename T>
Node<T>::Node(int r, int c, T v) {
    row = r;
    col = c;
    value = v;
}

template <typename T>
Node<T>::~Node() {

}

template <typename T>
T Node<T>::getValue() {
    return value;
}

template <typename T>
void Node<T>::setRight(Node<T>* r) {
    right = r;
}

template <typename T>
void Node<T>::setDown(Node<T>* d) {
    down = d;
}

template <typename T>
Node<T>* Node<T>::getRight() {
    return right;
}

template <typename T>
Node<T>* Node<T>::getDown() {
    return down;
}

template <typename T>
int Node<T>::getRow() {
    return row;
}

template <typename T>
int Node<T>::getCol() {
    return col;
}

template class Node<int>;
template class Node<double>;
template class Node<string>;
