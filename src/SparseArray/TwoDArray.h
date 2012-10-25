#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
using std::vector;

template <typename T>
class TwoDArray {
  private:
    vector< vector<T> > array;
    int rows;
    int cols;
    T def_value;

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
