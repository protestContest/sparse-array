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

TEST(ArrayTest, access) {
    TwoDArray<int>* ia = new TwoDArray<int>(12,12, 5);

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            EXPECT_EQ(ia->access(i,j), 5);
        }
    }

    delete ia;
}

TEST(ArrayTest, print) {
    TwoDArray<int>* ia = new TwoDArray<int>(3, 7, 0);
    ia->print();
    delete ia;
}

