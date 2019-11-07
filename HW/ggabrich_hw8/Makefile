CXXFLAGS= -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: testMain.cpp
	echo ---------compiling testMain.cpp to create executable program kruskals---------
	g++ -ggdb $(CXXFLAGS) testMain.cpp -o kruskals

clean:
	echo ---------------------removing executable program kruskals---------------------
	rm test_graph

all: clean main
