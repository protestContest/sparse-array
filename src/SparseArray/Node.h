#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    Node<T>* right;
    Node<T>* down;

  public:
    Node<T>(T v);
    ~Node<T>();

    T getValue();
    void setRight(const Node<T>* r);
    void setDown(const Node<T>* d);
};

#endif
