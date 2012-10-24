#ifndef __ARRAY_H__
#define __ARRAY_H__

template <typename T>
class TwoDArray {
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
