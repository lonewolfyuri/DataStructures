CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: testHash.cpp
	echo ---------compiling testHash.cpp to create executable program test_hash---------
	g++ -ggdb $(CXXFLAGS) testHash.cpp -o test_hash

clean:
	echo ---------------------removing executable program test_hash---------------------
	/bin/rm test_hash
