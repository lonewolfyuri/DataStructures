CXXFLAGS= -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: testTree.cpp
	echo ---------compiling testTree.cpp to create executable program test_tree---------
	g++ -ggdb $(CXXFLAGS) testTree.cpp -o test_tree

clean:
	echo ---------------------removing executable program test_hash---------------------
	rm test_tree

all: clean main
