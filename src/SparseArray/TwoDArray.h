#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
#include "Node.h"
using std::vector;

template <typename T>
class TwoDArray {
  private:
    int numRows;
    int numCols;
    T def_value;

    vector< Node<T>* >* rows;
    vector< Node<T>* >* cols;

  public:
    TwoDArray<T>(int r, int c, T def);
    ~TwoDArray<T>();

    void insert(int r, int c, T value);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
