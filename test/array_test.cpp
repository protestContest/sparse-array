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

    TwoDArray<string>* sa1 = new TwoDArray<string>(1, 1, "");
    delete sa1;
    TwoDArray<string>* sa2 = new TwoDArray<string>(2423, 341, "test string");
    delete sa2;
}

TEST(ArrayTest, access) {
    TwoDArray<int>* ia = new TwoDArray<int>(12,12, 5);

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            EXPECT_EQ(ia->access(i,j), 5);
        }
    }
    delete ia;


    TwoDArray<double>* da = new TwoDArray<double>(12,12, 4.999);

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            EXPECT_EQ(da->access(i,j), 4.999);
        }
    }
    delete da;

    TwoDArray<string>* sa = new TwoDArray<string>(12,12, "hi");

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            EXPECT_EQ(sa->access(i,j), "hi");
        }
    }
    delete sa;
}

TEST(ArrayTest, print) {
    TwoDArray<int>* ia = new TwoDArray<int>(3, 7, 0);
    ia->print();
    delete ia;

    TwoDArray<double>* da = new TwoDArray<double>(2, 6, 1.2);
    da->print();
    delete da;

    TwoDArray<string>* sa = new TwoDArray<string>(1, 4, "test");
    sa->print();
    delete sa;
}

TEST(ArrayTest, getSize) {
    TwoDArray<int>* ia = new TwoDArray<int>(5, 4, 1);
    EXPECT_EQ(ia->getNumRows(), 5);
    EXPECT_EQ(ia->getNumCols(), 4);
    delete ia;

    TwoDArray<double>* da = new TwoDArray<double>(16,38, 2.103);
    EXPECT_EQ(da->getNumCols(), 38);
    EXPECT_EQ(da->getNumRows(), 16);
    delete da;
}
