#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    int row;
    int col;
    Node<T>* right;
    Node<T>* down;

  public:
    Node<T>(int r, int c, T v);
    ~Node<T>();

    T getValue();
    void setRight(Node<T>* r);
    void setDown(Node<T>* d);
    Node<T>* getRight();
    Node<T>* getDown();
    int getRow();
    int getCol();
};

#endif
