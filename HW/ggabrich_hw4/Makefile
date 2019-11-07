CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant 
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: nest_bal test_stack test_queue

nest_bal: nest_main.cpp
	echo ---------compiling nest_main.cpp to create executable program nest_bal-----------
	g++  -ggdb  -std=c++11 $(CXXFLAGS) nest_main.cpp -o nest_bal

test_stack: stack_main.cpp
	echo ---------compiling stack_main.cpp to create executable program test_stack-----------
	g++  -ggdb  -std=c++11 $(CXXFLAGS) stack_main.cpp -o test_stack

test_queue: queue_main.cpp
	echo ---------compiling queue_main.cpp to create executable program test_queue-----------
	g++  -ggdb  -std=c++11 $(CXXFLAGS) queue_main.cpp -o test_queue

clean:
	echo ----------------removing executable program main-----------------
	/bin/rm nest_bal test_stack test_queue


