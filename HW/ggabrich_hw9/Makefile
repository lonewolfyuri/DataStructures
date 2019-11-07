CXXFLAGS= -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: testMain.cpp
	echo ---------compiling testMain.cpp to create executable program dijkstras---------
	g++ -ggdb $(CXXFLAGS) testMain.cpp -o dijkstras

clean:
	echo ---------------------removing executable program dijkstras---------------------
	rm dijkstras

test: testQ.cpp
	echo ---------compiling testQ.cpp to create executable program testQ---------
	g++ -ggdb $(CXXFLAGS) testQ.cpp -o testQ

all: clean test main
