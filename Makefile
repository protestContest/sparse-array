BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
SRC_INCLUDES = -I$(SRC)
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CC = g++
CFLAGS = -Wall -Wextra

ARRAY_ARRAY = $(SRC)/ArrayArray/TwoDArray.o


array_test: $(TEST)/array_test.cpp $(GTEST_MAINA) $(BUILD) $(ARRAY_ARRAY)
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(ARRAY_ARRAY) $(TEST)/array_test.cpp -o $(BUILD)/array_test -pthread

$(ARRAY_ARRAY):
	cd $(SRC)/ArrayArray && $(MAKE)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

$(BUILD):
	mkdir -p build/

clean:
	rm -rf build/*
	cd $(GTEST)/make && $(MAKE) clean
	cd $(SRC)/ArrayArray && $(MAKE) clean
