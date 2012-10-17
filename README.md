# CSCI 333 -- Fall 2012
## Project 2 -- TwoDArray implementations
### Due date: Friday, October 26, 2012 at 11:55PM

A templated TwoDArray has the following API:

``
//r is the number of rows
//c is the number of columns
//def is the default value
TwoDArray<T>(int r, int c, T def);

//destructor
~TwoDArray<T>();

//insert the value v at index r,c
void insert(int r, int c, T value);

//get the value at index r,c
T access(int r, int c);

//set the value at index r,c back to the default value
void remove(int r, int c);

//print the TwoDArray
void print();

//getters for iteration
int getNumRows();
int getNumCols();   
``

Your job is to implement a TwoDArray in 3 ways: as an actual
2-dimensional array, as a vector-of-vectors, and as a Sparse
Array.

Like in project 1, you’ll have a single Makefile in the root
directory that should build all source files and tests. Your
unit tests should use the Google C++ testing framework and
should carefully test ALL METHODS IN THE PUBLIC API FOR ALL
IMPLEMENTATIONS. You will receive 10 points in extra credit if
you can create a single test cpp file that tests all
implementation using different compiler actions in your
makefile.

Creating an actual 2D array in C++ is slightly non-trivial.
You’ll actually create a pointer-to-pointer reference, and then
create the 2D array using a for-loop. Here’s an example of
creating a 10x10 2D integer array:

``
int** theArray = new int*[10];

for(int i = 0; i < 10; ++i) {
	theArray[i] = new int[10];
}

``
