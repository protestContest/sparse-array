#include "gtest/gtest.h"
#include <iostream>
#include "TwoDArray.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

TEST(ArrayTest, Constructor) {
    TwoDArray<int>* ia1 = new TwoDArray<int>(1,1,0);
    delete ia1;

    TwoDArray<int>* ia2 = new TwoDArray<int>(1000,1000,256);
    delete ia2;

    TwoDArray<double>* da1 = new TwoDArray<double>(1,1, 0.5);
    delete da1;

    TwoDArray<double>* da2 = new TwoDArray<double>(1000,1000, 3.1459);
    delete da2;

}

