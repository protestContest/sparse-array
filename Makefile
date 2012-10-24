BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CFLAGS = -Wall -Wextra


array_test: $(TEST)/array_test.cpp $(GTEST_MAINA) $(BUILD)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(TEST)/array_test.cpp -o $(BUILD)/array_test -pthread

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

$(BUILD):
	mkdir -p build/

clean:
	rm -rf build/*
	cd $(GTEST)/make && $(MAKE) clean
