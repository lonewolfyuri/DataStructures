// George Gabricht
//
// ggabrich - 56735102


#include "ArrayStack.hpp"
#include "LinkedStack.hpp"
using namespace std;

void testStack(string infile, string outfile, Stack * stk); 

int main(int argc, char* argv[]) { // O(N)
	const char * infile_name = argc > 1 ? argv[1] : "random.txt";
	const char * outfile_arr_name = argc > 2 ? argv[2] : "ArrayStackOutput.txt";
	const char * outfile_link_name = argc > 3 ? argv[3] : "LinkedStackOutput.txt";
	
	ArrayStack arrStack(45500);
	LinkedStack linkStack;
	
	testStack(infile_name, outfile_arr_name, &arrStack);
	testStack(infile_name, outfile_link_name, &linkStack);

	return 0;
}

void testStack(string infile, string outfile, Stack * stk) { // O(N)
	ifstream in;
	in.open(infile);
	if (in.is_open()) {
		fillAll(stk, in);
	}
	
	ofstream out;
	out.open(outfile);
	if (out.is_open()) {
		emptyAll(stk, out);
	}
}	


