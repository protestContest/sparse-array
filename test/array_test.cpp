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

TEST(ArrayTest, insert) {
    TwoDArray<int>* ia = new TwoDArray<int>(14, 15, 0);
    ia->insert(2,3, 7);
    ia->insert(3,2, 14);
    ia->insert(13,14, 100);

    EXPECT_EQ(ia->access(2,3), 7);
    EXPECT_EQ(ia->access(3,2), 14);
    EXPECT_EQ(ia->access(13,14), 100);

    delete ia;


    TwoDArray<double>* da = new TwoDArray<double>(14, 15, 0.0);
    da->insert(2,3, .7);
    da->insert(3,2, 1.4);
    da->insert(13,14, 100.10);

    EXPECT_EQ(da->access(2,3), .7);
    EXPECT_EQ(da->access(3,2), 1.4);
    EXPECT_EQ(da->access(13,14), 100.1);

    delete da;


    TwoDArray<string>* sa = new TwoDArray<string>(14, 15, "");
    sa->insert(2,3, "hello");
    sa->insert(3,2, "world");
    sa->insert(13,14, "!");

    EXPECT_EQ(sa->access(2,3), "hello");
    EXPECT_EQ(sa->access(3,2), "world");
    EXPECT_EQ(sa->access(13,14), "!");

    delete sa;
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

TEST(ArrayTest, remove) {
    TwoDArray<int>* ia = new TwoDArray<int>(21,12, 3);
    EXPECT_EQ(ia->access(4,5), 3);
    EXPECT_EQ(ia->access(15,10), 3);
    ia->insert(4,5, 1024);
    ia->insert(15,10, 312);
    EXPECT_EQ(ia->access(4,5), 1024);
    EXPECT_EQ(ia->access(15,10), 312);
    ia->remove(4,5);
    EXPECT_EQ(ia->access(4,5), 3);
    ia->remove(15,10);
    EXPECT_EQ(ia->access(15,10), 3);
    delete ia;

    TwoDArray<double>* da = new TwoDArray<double>(21,12, 1.24);
    EXPECT_EQ(da->access(4,5), 1.24);
    EXPECT_EQ(da->access(15,10), 1.24);
    da->insert(4,5, 10.24);
    da->insert(15,10, 3.12);
    EXPECT_EQ(da->access(4,5), 10.24);
    EXPECT_EQ(da->access(15,10), 3.12);
    da->remove(4,5);
    EXPECT_EQ(da->access(4,5), 1.24);
    da->remove(15,10);
    EXPECT_EQ(da->access(15,10), 1.24);
    delete da;

    TwoDArray<string>* sa = new TwoDArray<string>(21,12, "asdf");
    EXPECT_EQ(sa->access(4,5), "asdf");
    EXPECT_EQ(sa->access(15,10), "asdf");
    sa->insert(4,5, "something");
    sa->insert(15,10, "else");
    EXPECT_EQ(sa->access(4,5), "something");
    EXPECT_EQ(sa->access(15,10), "else");
    sa->remove(4,5);
    EXPECT_EQ(sa->access(4,5), "asdf");
    sa->remove(15,10);
    EXPECT_EQ(sa->access(15,10), "asdf");
    delete sa;

}

TEST(ArrayTest, print) {
    TwoDArray<int>* ia = new TwoDArray<int>(3, 7, 0);
    ia->print();
    delete ia;

    TwoDArray<double>* da = new TwoDArray<double>(2, 6, 1.2);
    da->insert(1, 5, 3.7);
    da->insert(0, 2, 0.9);
    da->print();
    delete da;

    TwoDArray<string>* sa = new TwoDArray<string>(1, 4, "test");
    sa->insert(0,2, "sup dawg");
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

    TwoDArray<string>* sa = new TwoDArray<string>(40,12, "strings");
    EXPECT_EQ(sa->getNumCols(), 12);
    EXPECT_EQ(sa->getNumRows(), 40);
    delete sa;
}
