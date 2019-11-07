// George Gabricht
//
// ggabrich - 56735102


#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
using namespace std;

void testQueue(string infile, string outfile, Queue * que);

int main(int argc, char* argv[]) { // O(N)
        const char * infile_name = argc > 1 ? argv[1] : "random.txt";
        const char * outfile_arr_name = argc > 2 ? argv[2] : "ArrayQueueOutput.txt";
        const char * outfile_link_name = argc > 3 ? argv[3] : "LinkedQueueOutput.txt";

        ArrayQueue arrQueue(45500);
        LinkedQueue linkQueue;

        testQueue(infile_name, outfile_arr_name, &arrQueue);
        testQueue(infile_name, outfile_link_name, &linkQueue);

        return 0;
}

void testQueue(string infile, string outfile, Queue * que) { // O(N)
        ifstream in;
        in.open(infile);
        if (in.is_open()) {
                fillAll(que, in);
        }

        ofstream out;
        out.open(outfile);
        if (out.is_open()) {
                emptyAll(que, out);
        }
}
