#include "Node.h"
#include <assert.h>

template <typename T>
Node<T>::Node(T v) {
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
void Node<T>::setRight(const Node<T>* r) {
    right = r;
}

template <typename T>
void Node<T>::setDown(const Node<T>* d) {
    down = d;
}
