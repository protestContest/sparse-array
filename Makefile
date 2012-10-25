BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
SRC_INCLUDES = -I$(SRC)
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CC = g++
CFLAGS = -Wall -Wextra -ggdb

ARRAY_ARRAY = $(SRC)/ArrayArray/TwoDArray.o
VECTOR_ARRAY = $(SRC)/VectorArray/TwoDArray.o
SPARSE_ARRAY = $(SRC)/SparseArray/TwoDArray.o
NODE = $(SRC)/SparseArray/Node.o



all: sparse_test vector_test array_test

sparse_test: $(TEST)/array_test.cpp $(GTEST_MAINA) $(BUILD) $(SPARSE_ARRAY)
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(SPARSE_ARRAY) $(NODE) $(TEST)/array_test.cpp -o $(BUILD)/sparse_test -pthread

vector_test: $(TEST)/array_test.cpp $(GTEST_MAINA) $(BUILD) $(VECTOR_ARRAY)
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(VECTOR_ARRAY) $(TEST)/array_test.cpp -o $(BUILD)/vector_test -pthread

array_test: $(TEST)/array_test.cpp $(GTEST_MAINA) $(BUILD) $(ARRAY_ARRAY)
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(ARRAY_ARRAY) $(TEST)/array_test.cpp -o $(BUILD)/array_test -pthread



$(ARRAY_ARRAY): $(SRC)/ArrayArray/TwoDArray.cpp $(SRC)/ArrayArray/TwoDArray.h
	cd $(SRC)/ArrayArray && $(MAKE)

$(VECTOR_ARRAY): $(SRC)/VectorArray/TwoDArray.cpp $(SRC)/VectorArray/TwoDArray.h
	cd $(SRC)/VectorArray && $(MAKE)

$(SPARSE_ARRAY): $(SRC)/SparseArray/TwoDArray.cpp $(SRC)/SparseArray/TwoDArray.h $(SRC)/SparseArray/Node.h $(SRC)/SparseArray/Node.cpp
	cd $(SRC)/SparseArray && $(MAKE)



$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

$(BUILD):
	mkdir -p build/



clean:
	rm -rf build/*
	rm -rf src/TwoDArray.h
	cd $(GTEST)/make && $(MAKE) clean
	cd $(SRC)/ArrayArray && $(MAKE) clean
	cd $(SRC)/VectorArray && $(MAKE) clean
	cd $(SRC)/SparseArray && $(MAKE) clean
