CXXFLAGS= -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: testSort.cpp
	echo ---------compiling testSort.cpp to create executable program test_sort---------
	g++ -ggdb $(CXXFLAGS) testSort.cpp -o test_sort

clean:
	echo ---------------------removing executable program test_sort---------------------
	rm test_sort

all: clean main
